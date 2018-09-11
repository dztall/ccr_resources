struct opts {
	int no_options;
	int quiet;
	int bare;
	int initial_commit;
	uint32_t shared;
	const char *template;
	const char *gitdir;
	const char *dir;
};

int gitprefix(create_initial_commit)(git_repository *repo);
int gitprefix(parse_opts)(struct opts *o, int argc, char *argv[]);


int gitprefix(init) (int argc, char *argv[])
{
	git_repository *repo = NULL;
	struct opts o = { 1, 0, 0, 0, GIT_REPOSITORY_INIT_SHARED_UMASK, 0, 0, 0 };

	git_libgit2_init();

	if (gitprefix(parse_opts)(&o, argc, argv)) {
		git_libgit2_shutdown();
		return -2;
	}

	/* Initialize repository. */

	if (o.no_options) {
		/**
		 * No options were specified, so let's demonstrate the default
		 * simple case of git_repository_init() API usage...
		 */
		if (git_repository_init(&repo, o.dir, 0)) {
			git_repository_free(repo);
			git_libgit2_shutdown();
			giterror("Could not initialize repository");
		}
	}
	else {
		/**
		 * Some command line options were specified, so we'll use the
		 * extended init API to handle them
		 */
		git_repository_init_options initopts = GIT_REPOSITORY_INIT_OPTIONS_INIT;
		initopts.flags = GIT_REPOSITORY_INIT_MKPATH;

		if (o.bare)
			initopts.flags |= GIT_REPOSITORY_INIT_BARE;

		if (o.template) {
			initopts.flags |= GIT_REPOSITORY_INIT_EXTERNAL_TEMPLATE;
			initopts.template_path = o.template;
		}

		if (o.gitdir) {
			/**
			 * If you specified a separate git directory, then initialize
			 * the repository at that path and use the second path as the
			 * working directory of the repository (with a git-link file)
			 */
			initopts.workdir_path = o.dir;
			o.dir = o.gitdir;
		}

		if (o.shared != 0)
			initopts.mode = o.shared;

		if (git_repository_init_ext(&repo, o.dir, &initopts)) {
			git_repository_free(repo);
			git_libgit2_shutdown();
			giterror("Could not initialize repository");
		}
	}

	/** Print a message to stdout like "git init" does. */

	if (!o.quiet) {
		if (o.bare || o.gitdir)
			o.dir = git_repository_path(repo);
		else
			o.dir = git_repository_workdir(repo);
		
		char * tmp = strdup(o.dir);
		
		int idx = strlen(tmp);
		
		if (tmp[idx-2] == '.' && tmp[idx-1] == '/') {
			tmp[idx-2] = '\0';
			tmp[idx-1] = '\0';
		}
		else if (tmp[idx-2] == '/' && tmp[idx-1] == '/') {
			tmp[idx-2] = '\0';
			tmp[idx-1] = '\0';
		}
		else if (tmp[idx-1] == '.') {
			tmp[idx-1] = '\0';
		}
		
		printf("Initialized empty Git repository in %s.git\n", tmp);
		free(tmp);
	}

	/**
	 * As an extension to the basic "git init" command, this example
	 * gives the option to create an empty initial commit.  This is
	 * mostly to demonstrate what it takes to do that, but also some
	 * people like to have that empty base commit in their repo.
	 */
	/*
	if (o.initial_commit) {
		if(!gitprefix(create_initial_commit)(repo))
			printf("Created empty initial commit\n");
		else {
			git_repository_free(repo);
			git_libgit2_shutdown();
			giterror("failed to create empty initial commit");
		}
	}
	*/

	git_repository_free(repo);
	git_libgit2_shutdown();

	return 0;
}

int gitprefix(create_initial_commit)(git_repository *repo)
{
	git_signature *sig;
	git_index *index;
	git_oid tree_id, commit_id;
	git_tree *tree;

	/** First use the config to initialize a commit signature for the user. */
	
	if (git_signature_default(&sig, repo) < 0) {
		if (git_signature_new(&sig, "mgood7123","smallville7123@gmail.com",0,0) < 0) {
			git_signature_free(sig);
			giterror("Unable to create a commit signature.\n%s",
		      "Perhaps 'user.name' and 'user.email' are not set");
		}
	}

	/* Now let's create an empty tree for this commit */

	if (git_repository_index(&index, repo) < 0) {
		git_index_free(index);
		git_signature_free(sig);
		giterror("Could not open repository index", NULL);
	}

	/**
	 * Outside of this example, you could call git_index_add_bypath()
	 * here to put actual files into the index.  For our purposes, we'll
	 * leave it empty for now.
	 */

	if (git_index_write_tree(&tree_id, index) < 0) {
		git_index_free(index);
		git_tree_free(tree);
		git_signature_free(sig);
		giterror("Unable to write initial tree from index", NULL);
	}

	git_index_free(index);

	if (git_tree_lookup(&tree, repo, &tree_id) < 0) {
		git_tree_free(tree);
		git_signature_free(sig);
		giterror("Could not look up initial tree", NULL);
	}

	/**
	 * Ready to create the initial commit.
	 *
	 * Normally creating a commit would involve looking up the current
	 * HEAD commit and making that be the parent of the initial commit,
	 * but here this is the first commit so there will be no parent.
	 */

	if (git_commit_create_v(
			&commit_id, repo, "HEAD", sig, sig,
			NULL, "Initial commit", tree, 0) < 0) {
		git_tree_free(tree);
		git_signature_free(sig);
		giterror("Could not create the initial commit", NULL);
	}

	/** Clean up so we don't leak memory. */

	git_tree_free(tree);
	git_signature_free(sig);
	return 0;
}


int gitprefix(parse_opts)(struct opts *o, int argc, char *argv[])
{
	struct args_info args = ARGS_INFO_INIT;
	const char *sharedarg;

	/** Process arguments. */

	for (args.pos = 1; args.pos < argc; ++args.pos) {
		char *a = argv[args.pos];

		if (a[0] == '-')
			o->no_options = 0;

		if (a[0] != '-') {
			if (o->dir != NULL)
				giterror("extra argument: %s", a);
			o->dir = a;
		}
		else if (!strcmp(a, "-q") || !strcmp(a, "--quiet"))
			o->quiet = 1;
		else if (!strcmp(a, "--bare"))
			o->bare = 1;
		else if (!strcmp(a, "--shared"))
			o->shared = GIT_REPOSITORY_INIT_SHARED_GROUP;
		else if (!strcmp(a, "--initial-commit"))
			o->initial_commit = 1;
		else if (match_str_arg(&sharedarg, &args, "--shared"))
			o->shared = parse_shared(sharedarg);
		else if (!match_str_arg(&o->template, &args, "--template") ||
		         !match_str_arg(&o->gitdir, &args, "--separate-git-dir"))
			giterror("unknown option: %s", a);
	}

	if (!o->dir) o->dir = "./";
	return 0;
}

