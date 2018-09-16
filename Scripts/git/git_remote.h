/*
 * libgit2 "remote" example - shows how to modify remotes for a repo
 *
 * Written by the libgit2 contributors
 *
 * To the extent possible under law, the author(s) have dedicated all copyright
 * and related and neighboring rights to this software to the public domain
 * worldwide. This software is distributed without any warranty.
 *
 * You should have received a copy of the CC0 Public Domain Dedication along
 * with this software. If not, see
 * <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

/**
 * This is a sample program that is similar to "git remote".  See the
 * documentation for that (try "git help remote") to understand what this
 * program is emulating.
 *
 * This demonstrates using the libgit2 APIs to modify remotes of a repository.
 */

enum gitprefix(remote_subcmd) {
	subcmd_add,
	subcmd_ls,
	subcmd_remove,
	subcmd_rename,
	subcmd_seturl,
	subcmd_show,
};

struct gitprefix(remote_opts) {
	enum gitprefix(remote_subcmd) cmd;

	/* for command-specific args */
	int argc;
	char **argv;
};

int gitprefix(remote_cmd_add)(git_repository *repo, struct gitprefix(remote_opts) *o);
int gitprefix(remote_ls_remote)(git_repository *repo, struct gitprefix(remote_opts) *o);
int gitprefix(remote_cmd_remove)(git_repository *repo, struct gitprefix(remote_opts) *o);
int gitprefix(remote_cmd_rename)(git_repository *repo, struct gitprefix(remote_opts) *o);
int gitprefix(remote_cmd_seturl)(git_repository *repo, struct gitprefix(remote_opts) *o);
int gitprefix(remote_cmd_show)(git_repository *repo, struct gitprefix(remote_opts) *o);

int gitprefix(remote_parse_subcmd)(struct gitprefix(remote_opts) *opt, int argc, char **argv);
int gitprefix(remote_usage)(const char *msg, const char *arg);

int gitprefix(remote) (int argc, char *argv[])
{
	int retval = 0;
	struct gitprefix(remote_opts) opt = {0};
	git_repository *repo = NULL;

	if (gitprefix(remote_parse_subcmd)(&opt, argc, argv) == -1) return -1;

	git_libgit2_init();
	
	gitopenrepo(&repo,NULL);

	switch (opt.cmd)
	{
	case subcmd_add:
		retval = gitprefix(remote_cmd_add)(repo, &opt);
		break;
	case subcmd_ls:
		retval = gitprefix(remote_ls_remote)(repo, &opt);
		break;
	case subcmd_remove:
		retval = gitprefix(remote_cmd_remove)(repo, &opt);
		break;
	case subcmd_rename:
		retval = gitprefix(remote_cmd_rename)(repo, &opt);
		break;
	case subcmd_seturl:
		retval = gitprefix(remote_cmd_seturl)(repo, &opt);
		break;
	case subcmd_show:
		retval = gitprefix(remote_cmd_show)(repo, &opt);
		break;
	}
	
	if (!using_defined) {
		if (username) {
			free(username);
			username = NULL;
		}
		if (password) {
			free(password);
			password = NULL;
		}
	}

	git_libgit2_shutdown();

	return retval;
}

int gitprefix(does_remote_exist)(git_repository *repo, char * name) {
	
	if(name == NULL || strcmp(name, "") == 0) giterror("must specify a name");
	
	git_strarray remotes = {0};
	
	if (git_remote_list(&remotes, repo)) {
		giterror("could not retrieve remotes");
	}

	for (int i = 0; i < (int) remotes.count; i++) if (strcmp(remotes.strings[i], name) == 0) {
		git_strarray_free(&remotes);
		giterror("remote \"%s\" already exists", name);
	}
	git_strarray_free(&remotes);
	return 0;
}

int gitprefix(remote_cmd_add)(git_repository *repo, struct gitprefix(remote_opts) *o)
{
	char *name, *url;
	git_remote *remote = {0};

	if (o->argc != 2)
		return gitprefix(remote_usage)("you need to specify a name and URL", NULL);

	name = o->argv[0];
	url = fixurl(o->argv[1]);
	
	if (gitprefix(does_remote_exist)(repo, name)) return -1;

	if (git_remote_create(&remote, repo, name, url)) {
		giterror("could not create remote");
	}
	
	bool cred_acquire_called;
    git_remote_callbacks callbacks = GIT_REMOTE_CALLBACKS_INIT;
    callbacks.credentials = cred_acquire_cb;
	if (git_remote_connect(remote, GIT_DIRECTION_PUSH, &callbacks, NULL, NULL)) {
		printf("remote \"%s\" at url \"%s\" does not exist on server, attempting to create %s\n", name, url, url);
		int cmdlen = strlen("push ")+strlen(name)+strlen(" master")+1;
		char * cmd = malloc(cmdlen);
		memset(cmd, 0, cmdlen);
		snprintf(cmd, cmdlen, "push %s master", name);
		ps(cmd)
		gitprefix(curl_create)(url);
		git(cmd);
		free(cmd);
		return -1;
	}
	return 0;
}

int gitprefix(remote_cmd_remove)(git_repository *repo, struct gitprefix(remote_opts) *o)
{
	char *name;

	if (o->argc != 1)
		return gitprefix(remote_usage)("you need to specify a name", NULL);

	name = o->argv[0];

	if (git_remote_delete(repo, name)) {
		giterror("could not delete remote");
	}

	return 0;
}

int gitprefix(remote_cmd_rename)(git_repository *repo, struct gitprefix(remote_opts) *o)
{
	int i, retval;
	char *old, *new;
	git_strarray problems = {0};

	if (o->argc != 2)
		return gitprefix(remote_usage)("you need to specify old and new remote name", NULL);

	old = o->argv[0];
	new = o->argv[1];

	retval = git_remote_rename(&problems, repo, old, new);
	if (!retval)
		return 0;

	for (i = 0; i < (int) problems.count; i++) {
		puts(problems.strings[0]);
	}

	git_strarray_free(&problems);

	return retval;
}

int gitprefix(remote_cmd_seturl)(git_repository *repo, struct gitprefix(remote_opts) *o)
{
	int i, retval, push = 0;
	char *name = NULL, *url = NULL;

	for (i = 0; i < o->argc; i++) {
		char *arg = o->argv[i];

		if (!strcmp(arg, "--push")) {
			push = 1;
		} else if (arg[0] != '-' && name == NULL) {
			name = arg;
		} else if (arg[0] != '-' && url == NULL) {
			url = fixurl(arg);
		} else {
			return gitprefix(remote_usage)("invalid argument to set-url", arg);
		}
	}

	if (name == NULL || url == NULL)
		return gitprefix(remote_usage)("you need to specify remote and the new URL", NULL);

	if (push)
		retval = git_remote_set_pushurl(repo, name, url);
	else
		retval = git_remote_set_url(repo, name, url);

	if (retval) {
		giterror("could not set URL %s", url);
	}
	git_remote *remote = {0};
	if (git_remote_lookup(&remote, repo, name)) {
		git_remote_free(remote);
		giterror("could not look up remote");
	}
	
	bool cred_acquire_called;
    git_remote_callbacks callbacks = GIT_REMOTE_CALLBACKS_INIT;
    callbacks.credentials = cred_acquire_cb;
	if (git_remote_connect(remote, GIT_DIRECTION_PUSH, &callbacks, NULL, NULL)) {
		printf("remote \"%s\" at url \"%s\" does not exist on server, attempting to create %s\n", name, url, url);
		gitprefix(curl_create)(url);
		git_remote_free(remote);
		return -1;
	}
	git_remote_free(remote);

	return 0;
}

int gitprefix(remote_cmd_show)(git_repository *repo, struct gitprefix(remote_opts) *o)
{
	int i;
	const char *arg, *name, *fetch, *push;
	int verbose = 0;
	git_strarray remotes = {0};
	git_remote *remote = {0};

	for (i = 0; i < o->argc; i++) {
		arg = o->argv[i];

		if (!strcmp(arg, "-v") || !strcmp(arg, "--verbose")) {
			verbose = 1;
		}
	}

	if (git_remote_list(&remotes, repo)) {
		giterror("could not retrieve remotes");
	}

	for (i = 0; i < (int) remotes.count; i++) {
		name = remotes.strings[i];
		if (!verbose) {
			puts(name);
			continue;
		}

		if (git_remote_lookup(&remote, repo, name)) {
			git_remote_free(remote);
			git_strarray_free(&remotes);
			giterror("could not look up remote");
		}

		fetch = git_remote_url(remote);
		if (fetch)
			printf("%s\t%s (fetch)\n", name, fetch);
		push = git_remote_pushurl(remote);
		/* use fetch URL if no distinct push URL has been set */
		push = push ? push : fetch;
		if (push)
			printf("%s\t%s (push)\n", name, push);

		git_remote_free(remote);
	}

	git_strarray_free(&remotes);

	return 0;
}

int gitprefix(remote_parse_subcmd)(struct gitprefix(remote_opts) *opt, int argc, char **argv)
{
	char *arg = argv[1];
	enum subcmd cmd = 0;

	if (argc < 2)
		return gitprefix(remote_usage)("no command specified", NULL);

	if (!strcmp(arg, "add")) {
		cmd = subcmd_add;
	} else if (!strcmp(arg, "ls") || !strcmp(arg, "ls-remote")) {
		cmd = subcmd_ls;
	} else if (!strcmp(arg, "remove")) {
		cmd = subcmd_remove;
	} else if (!strcmp(arg, "rename")) {
		cmd = subcmd_rename;
	} else if (!strcmp(arg, "set-url")) {
		cmd = subcmd_seturl;
	} else if (!strcmp(arg, "show")) {
		cmd = subcmd_show;
	} else {
		return gitprefix(remote_usage)("command is not valid", arg);
	}
	opt->cmd = cmd;

	opt->argc = argc - 2; /* executable and subcommand are removed */
	opt->argv = argv + 2;
	return 0;
}

int gitprefix(remote_usage)(const char *msg, const char *arg)
{
	fputs("usage: remote add <name> <url>\n", stderr);
	fputs("       remote ls <remote> (alias for ls-remote, does exact same thing)\n", stderr);
	fputs("       remote ls-remote <remote>\n", stderr);
	fputs("       remote remove <name>\n", stderr);
	fputs("       remote rename <old> <new>\n", stderr);
	fputs("       remote set-url [--push] <name> <newurl>\n", stderr);
	fputs("       remote show [-v|--verbose]\n", stderr);

	if (msg && !arg)
		fprintf(stderr, "\n%s\n", msg);
	else if (msg && arg)
		fprintf(stderr, "\n%s: %s\n", msg, arg);
	return -1;
}


int gitprefix(remote_use_remote)(git_repository *repo, char *name)
{
	git_remote *remote = NULL;
	int error;
	const git_remote_head **refs;
	size_t refs_len, i;
	git_remote_callbacks callbacks = GIT_REMOTE_CALLBACKS_INIT;

	// Find the remote by name
	if (git_remote_lookup(&remote, repo, name)) {
		printf("remote \"%s\" doesnt exist, attempting to create anonymous remote \"%s\"\n", name, name);
		if (git_remote_create_anonymous(&remote, repo, name)) {
			git_remote_free(remote);
			giterror("anonymous remote \"%s\" could not be created exist", name);
		}
		printf("anonymous remote \"%s\" created successfully\n", name);
	}

	/**
	 * Connect to the remote and call the printing function for
	 * each of the remote references.
	 */
	callbacks.credentials = cred_acquire_cb;

	if (git_remote_connect(remote, GIT_DIRECTION_FETCH, &callbacks, NULL, NULL)) {
		git_remote_free(remote);
		giterror("could not connect to remote \"%s\", is it possible you forgot to add a URL to it? ( remote add %s <URL> ), error reason: ", name, name);
	}

	/**
	 * Get the list of references on the remote and print out
	 * their name next to what they point to.
	 */
	if (git_remote_ls(&refs, &refs_len, remote)) {
		git_remote_free(remote);
		giterror("could not obtain reference list from to remote \"%s\"", name);
	}

	for (i = 0; i < refs_len; i++) {
		char oid[GIT_OID_HEXSZ + 1] = {0};
		git_oid_fmt(oid, &refs[i]->oid);
		printf("%s\t%s\n", oid, refs[i]->name);
	}
	return 0;
}

int gitprefix(remote_ls_remote)(git_repository *repo, struct gitprefix(remote_opts) *o)
{
	if (o->argc == 0) {
		return gitprefix(remote_usage)("a remote is required, use <remote show> to show available remotes", NULL);
	}
	return gitprefix(remote_use_remote)(repo, o->argv[0]);
}
