/*
 * libgit2 "showindex" example - shows how to extract data from the index
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

// git3 status --git-dir=a/0

int gitprefix(stat) (int argc, char** argv)
{
	git_index *index;
	unsigned int i, ecount;
	char *dir = ".";
	size_t dirlen;
	char out[GIT_OID_HEXSZ+1];
	out[GIT_OID_HEXSZ] = '\0';
	
	

	git_libgit2_init();

	if (argc > 2) giterror("usage: showindex [<repo-dir>]", NULL);
	
	git_repository *repo;
	gitopenrepo(&repo, argv[1]);

	if (git_repository_index(&index, repo)) {
		if (repo) git_repository_free(repo);
		if (index) git_index_free(index);
		giterror("could not open repository index");
	}
	git_index_read(index, 0);

	ecount = git_index_entrycount(index);
	if (!ecount)
		printf("Empty index\n");

	for (i = 0; i < ecount; ++i) {
		const git_index_entry *e = git_index_get_byindex(index, i);

		git_oid_fmt(out, &e->id);

		printf("File Path: %s\n", e->path);
		printf("    Stage: %d\n", git_index_entry_stage(e));
		printf(" Blob SHA: %s\n", out);
		printf("File Mode: %07o\n", e->mode);
		printf("File Size: %d bytes\n", (int)e->file_size);
		printf("Dev/Inode: %d/%d\n", (int)e->dev, (int)e->ino);
		printf("  UID/GID: %d/%d\n", (int)e->uid, (int)e->gid);
		printf("    ctime: %d\n", (int)e->ctime.seconds);
		printf("    mtime: %d\n", (int)e->mtime.seconds);
		printf("\n");
	}

	if (index) git_index_free(index);
	if (repo) git_repository_free(repo);
	git_libgit2_shutdown();

	return 0;
}

char * find_renamed_file(git_repository * repo, char * file_to_look_for) {
	git_index *index;
	int found = 0, match = 0;
	unsigned int i, ecount;
	size_t dirlen;
	char out[GIT_OID_HEXSZ+1];
	out[GIT_OID_HEXSZ] = '\0';
	char out2[GIT_OID_HEXSZ+1];
	out2[GIT_OID_HEXSZ] = '\0';
	if (git_repository_index(&index, repo)) {
		if (repo) git_repository_free(repo);
		if (index) git_index_free(index);
		giterror("could not open repository index");
	}

	git_index_read(index, 0);

	ecount = git_index_entrycount(index);
	if (!ecount) printf("Empty index\n");
	puts("listing all files first");
	for (i = 0; i < ecount; ++i) {
		const git_index_entry *e = git_index_get_byindex(index, i);
		printf("File Path: %s\n", e->path);
	}
	i = 0;
	printf("looking for %s\n", file_to_look_for);
	for (i = 0; i < ecount; ++i) {
		if (match) break;
		const git_index_entry *e = git_index_get_byindex(index, i);
		if (!found) if (strcmp(e->path, file_to_look_for) == 0) {
			found = 1;
			git_oid_fmt(out, &e->id);
			printf("File Path: %s\n", e->path);
			printf("    Stage: %d\n", git_index_entry_stage(e));
			printf(" Blob SHA: %s\n", out);
			printf("file found, looking for all other files with SHA %s\n", out);
			i = -1;
		}
		if (found) {
			git_oid_fmt(out2, &e->id);
			if (strcmp(out2, out) == 0 && strcmp(e->path, file_to_look_for) == -1) {
				printf("File Path: %s\n", e->path);
				printf("    Stage: %d\n", git_index_entry_stage(e));
				printf(" Blob SHA: %s\n", out);
				match = 1;
			}
		}
	}

	if (index) git_index_free(index);
	if (match) return out2;
	puts("could not find any matching files");
	return NULL;
}

/*
	s // git_status_entry *
	s->head_to_index // git_diff_delta *
	s->head_to_index->flags // uint32_t
	s->head_to_index->new_file // git_diff_file
	s->head_to_index->new_file.flags // uint32_t
	s->head_to_index->new_file.id // git_oid
	s->head_to_index->new_file.id_abbrev // uint16_t
	s->head_to_index->new_file.mode // uint16_t
	s->head_to_index->new_file.path // const char *
	s->head_to_index->new_file.size // git_off_t
	s->head_to_index->nfiles // uint16_t
	s->head_to_index->old_file // git_diff_file
	s->head_to_index->old_file.flags // uint32_t
	s->head_to_index->old_file.id // git_oid
	s->head_to_index->old_file.id_abbrev // uint16_t
	s->head_to_index->old_file.mode // uint16_t
	s->head_to_index->old_file.path // const char *
	s->head_to_index->old_file.size // git_off_t
	s->head_to_index->similarity // uint16_t
	s->head_to_index->status // git_delta_t
	s->index_to_workdir // git_diff_delta *
	s->index_to_workdir->flags // uint32_t
	s->index_to_workdir->new_file // git_diff_file
	s->index_to_workdir->new_file.flags // uint32_t
	s->index_to_workdir->new_file.id // git_oid
	s->index_to_workdir->new_file.id_abbrev // uint16_t
	s->index_to_workdir->new_file.mode // uint16_t
	s->index_to_workdir->new_file.path // const char *
	s->index_to_workdir->new_file.size // git_off_t
	s->index_to_workdir->nfiles // uint16_t
	s->index_to_workdir->old_file // git_diff_file
	s->index_to_workdir->old_file.flags // uint32_t
	s->index_to_workdir->old_file.id // git_oid
	s->index_to_workdir->old_file.id_abbrev // uint16_t
	s->index_to_workdir->old_file.mode // uint16_t
	s->index_to_workdir->old_file.path // const char *
	s->index_to_workdir->old_file.size // git_off_t
	s->index_to_workdir->similarity // uint16_t
	s->index_to_workdir->status // git_delta_t
	s->status // git_status_t
*/

#define ifgitstat(x, y) \
	printf("%s checking if NULL\n", #x); \
	if (x == NULL) { \
		printf("%s is NULL\n", #x); \
	} else if (x != NULL) { \
		printf("%s is not NULL\n", #x); \
		y(x)

#define gitstat(x, y) \
	printf("%s checking if NULL\n", #x); \
	if (x == NULL) { \
		printf("%s is NULL\n", #x); \
	} else if (x != NULL) { \
		printf("%s is not NULL\n", #x); \
		y(x) \
	}
	
#define gitstat2(x, y) \
	if (x == NULL) { \
	} else if (x != NULL) { \
		y(x) \
	}
/*
	
void git_status_entry_info(git_status_entry *s) {
	ifgitstat(s, pp);
		ifgitstat(s->head_to_index, pp);
			gitstat(s->head_to_index->flags, puint32);
			ifgitstat(s->head_to_index->new_file, pp);
				gitstat(s->head_to_index->new_file.flags, puint32);
				gitstat(s->head_to_index->new_file.id, pi);
				gitstat(s->head_to_index->new_file.id_abbrev, puint32);
				gitstat(s->head_to_index->new_file.mode, puint16);
				gitstat(s->head_to_index->new_file.path, ps);
				gitstat(s->head_to_index->new_file.size, psize_t);
			}
			gitstat(s->head_to_index->nfiles, puint16);
			ifgitstat(s->head_to_index->old_file, pp);
				gitstat(s->head_to_index->old_file.flags, puint32);
				gitstat(s->head_to_index->old_file.id, pi);
				gitstat(s->head_to_index->old_file.id_abbrev, puint32);
				gitstat(s->head_to_index->old_file.mode, puint16);
				gitstat(s->head_to_index->old_file.path, ps);
				gitstat(s->head_to_index->old_file.size, psize_t);
			}
			gitstat(s->head_to_index->similarity, puint16);
			gitstat(s->head_to_index->status, pi);
		}
		
		ifgitstat(s->index_to_workdir, pp);
			gitstat(s->index_to_workdir->flags, puint32);
			ifgitstat(s->index_to_workdir->new_file, pp);
				gitstat(s->index_to_workdir->new_file.flags, puint32);
				gitstat(s->index_to_workdir->new_file.id, pi);
				gitstat(s->index_to_workdir->new_file.id_abbrev, puint32);
				gitstat(s->index_to_workdir->new_file.mode, puint16);
				gitstat(s->index_to_workdir->new_file.path, ps);
				gitstat(s->index_to_workdir->new_file.size, psize_t);
			}
			gitstat(s->index_to_workdir->nfiles, puint16);
			ifgitstat(s->index_to_workdir->old_file, pp);
				gitstat(s->index_to_workdir->old_file.flags, puint32);
				gitstat(s->index_to_workdir->old_file.id, pi);
				gitstat(s->index_to_workdir->old_file.id_abbrev, puint32);
				gitstat(s->index_to_workdir->old_file.mode, puint16);
				gitstat(s->index_to_workdir->old_file.path, ps);
				gitstat(s->index_to_workdir->old_file.size, psize_t);
			}
			gitstat(s->index_to_workdir->similarity, puint16);
			gitstat(s->index_to_workdir->status, pi);
		}
		
		gitstat(s->status, pi);
	}
}

*/

char SHA_head_to_index_NEW[GIT_OID_HEXSZ+1];
char SHA_head_to_index_OLD[GIT_OID_HEXSZ+1];
	
char SHA_index_to_workdir_NEW[GIT_OID_HEXSZ+1];
char SHA_index_to_workdir_OLD[GIT_OID_HEXSZ+1];

void git_status_entry_infos(git_status_entry *s, git_status_t a) {
	SHA_head_to_index_NEW[GIT_OID_HEXSZ] = '\0';
	SHA_head_to_index_OLD[GIT_OID_HEXSZ] = '\0';
	SHA_index_to_workdir_NEW[GIT_OID_HEXSZ] = '\0';
	SHA_index_to_workdir_OLD[GIT_OID_HEXSZ] = '\0';
	if (s != NULL) {
		if (s->status & a) {
			if(s->head_to_index != NULL) {
				git_oid_fmt(SHA_head_to_index_NEW, &s->head_to_index->new_file.id); ps(SHA_head_to_index_NEW)
				git_oid_fmt(SHA_head_to_index_OLD, &s->head_to_index->old_file.id); ps(SHA_head_to_index_OLD)
			}
			if(s->index_to_workdir != NULL) {
				git_oid_fmt(SHA_index_to_workdir_NEW, &s->index_to_workdir->new_file.id); ps(SHA_index_to_workdir_NEW)
				git_oid_fmt(SHA_index_to_workdir_OLD, &s->index_to_workdir->old_file.id); ps(SHA_index_to_workdir_OLD)
			}
		}
	}
}

enum {
	FORMAT_DEFAULT   = 0,
	FORMAT_LONG      = 1,
	FORMAT_SHORT     = 2,
	FORMAT_PORCELAIN = 3,
};

#define MAX_PATHSPEC 8

struct gitprefix(optsST) {
	git_status_options statusopt;
	char *repodir;
	char *pathspec[MAX_PATHSPEC];
	int npaths;
	int format;
	int zterm;
	int showbranch;
	int showsubmod;
	int repeat;
};

void gitprefix(parse_optsST)(struct opts *o, int argc, char *argv[]);
void gitprefix(show_branchST)(git_repository *repo, int format);
int gitprefix(ensure_there_are_changes_to_stash)(git_repository * repo, git_status_list *status);
void gitprefix(print_shortST)(git_repository *repo, git_status_list *status);
int gitprefix(print_submodST)(git_submodule *sm, const char *name, void *payload);

#define O_FLAGS GIT_STATUS_OPT_EXCLUDE_SUBMODULES | GIT_STATUS_OPT_INCLUDE_UNTRACKED | GIT_STATUS_OPT_RECURSE_UNTRACKED_DIRS | GIT_STATUS_OPT_INCLUDE_IGNORED | GIT_STATUS_OPT_RECURSE_IGNORED_DIRS | GIT_STATUS_OPT_INCLUDE_UNREADABLE | GIT_STATUS_OPT_RENAMES_FROM_REWRITES | GIT_STATUS_OPT_RENAMES_HEAD_TO_INDEX | GIT_STATUS_OPT_RENAMES_INDEX_TO_WORKDIR

int gitprefix(status)(int argc, char *argv[])
{
	git_repository *repo = NULL;
	git_status_list *status;
	struct gitprefix(optsST) o = { GIT_STATUS_OPTIONS_INIT, ".",0,0,0,0,0,0 };

	git_libgit2_init();

	o.statusopt.show  = GIT_STATUS_SHOW_INDEX_AND_WORKDIR;
	o.statusopt.flags = O_FLAGS;

	gitprefix(parse_optsST)(&o, argc, argv);

	gitopenrepo(&repo, NULL);

	if (git_repository_is_bare(repo))
		gitret(fatal("Cannot report status on bare repository",
			git_repository_path(repo)));

show_status:
	if (o.repeat)
		printf("\033[H\033[2J");

	/**
	 * Run status on the repository
	 *
	 * We use `git_status_list_new()` to generate a list of status
	 * information which lets us iterate over it at our
	 * convenience and extract the data we want to show out of
	 * each entry.
	 *
	 * You can use `git_status_foreach()` or
	 * `git_status_foreach_ext()` if you'd prefer to execute a
	 * callback for each entry. The latter gives you more control
	 * about what results are presented.
	 */

	if (o.showsubmod) {
		int submod_count = 0;
		gitret(check_lg2(git_submodule_foreach(repo, gitprefix(print_submodST), &submod_count),
			"Cannot iterate submodules", o.repodir));
	}

	gitret(check_lg2(git_status_list_new(&status, repo, &o.statusopt),
		"Could not get status, rename detection will be disabled", NULL));
	if (o.format == FORMAT_LONG)
		gitprefix(ensure_there_are_changes_to_stash)(repo, status);
	else {
		gitprefix(print_shortST)(repo, status);
	}
	if (status) git_status_list_free(status);


	if (o.repeat) {
		sleep(o.repeat);
		goto show_status;
	}
	if (repo) git_repository_free(repo);
	git_libgit2_shutdown();
	return 0;
}

/**
 * If the user asked for the branch, let's show the short name of the
 * branch.
 */
void gitprefix(show_branchST)(git_repository *repo, int format)
{
	int error = 0;
	const char *branch = NULL;
	git_reference *head = NULL;

	error = git_repository_head(&head, repo);

	if (error == GIT_EUNBORNBRANCH || error == GIT_ENOTFOUND)
		branch = NULL;
	else if (!error) {
		branch = git_reference_shorthand(head);
		git_reference_free(head);
	} else
		gitret(check_lg2(error, "failed to get current branch", NULL));

	if (format == FORMAT_LONG)
		printf("# On branch %s\n",
			branch ? branch : "Not currently on any branch.");
	else
		printf("## %s\n", branch ? branch : "HEAD (no branch)");
}

/**
* This function print out an output similar to git's status command
* in long form, including the command-line hints.
*/

#include "callbacks/status.h"

int nothing(void) {
	int changes_in_index = 0, changed_in_workdir = 0, has_untracked_files = 0;
	for (int i = 0; i < status_list_index; i++) {
		char * istatus = NULL;
		if (status_list[i].status == GIT_STATUS_CURRENT)
			continue;
		if (status_list[i].status & GIT_STATUS_INDEX_NEW)
			istatus = "new file: ";
		if (status_list[i].status & GIT_STATUS_INDEX_MODIFIED)
			istatus = "modified: ";
		if (status_list[i].status & GIT_STATUS_INDEX_DELETED)
			istatus = "deleted:  ";
		if (status_list[i].status & GIT_STATUS_INDEX_RENAMED)
			istatus = "renamed:  ";
		if (status_list[i].status & GIT_STATUS_INDEX_TYPECHANGE)
			istatus = "typechange:";
		if (istatus == NULL)
			continue;
		changes_in_index = 1;
	}
	
	for (int i = 0; i < status_list_index; i++) {
		char *wstatus = NULL;
		if (status_list[i].status & GIT_STATUS_WT_MODIFIED)
			wstatus = "modified: ";
		if (status_list[i].status & GIT_STATUS_WT_DELETED)
			wstatus = "deleted:  ";
		if (status_list[i].status & GIT_STATUS_WT_RENAMED)
			wstatus = "renamed:  ";
		if (status_list[i].status & GIT_STATUS_WT_TYPECHANGE)
			wstatus = "typechange:";
		if (wstatus == NULL)
			continue;
		changed_in_workdir = 1;
	}

	for (int i = 0; i < status_list_index; i++) if (status_list[i].status == GIT_STATUS_WT_NEW) has_untracked_files = 1;
	
	if (!changes_in_index && !changed_in_workdir && !has_untracked_files) return -1;
	return 0;
}


int gitprefix(ensure_there_are_changes_to_stash)(git_repository *repo, git_status_list *status)
{
	int error;
	git_status_options opts = GIT_STATUS_OPTIONS_INIT;

	opts.show  = GIT_STATUS_SHOW_INDEX_AND_WORKDIR;
	//opts.flags = GIT_STATUS_OPT_EXCLUDE_SUBMODULES | GIT_STATUS_OPT_INCLUDE_UNTRACKED | GIT_STATUS_OPT_RECURSE_UNTRACKED_DIRS | GIT_STATUS_OPT_INCLUDE_IGNORED | GIT_STATUS_OPT_RECURSE_IGNORED_DIRS;
	opts.flags = O_FLAGS;
	
	status_list_index = 0;
	/*
	pi(GIT_STATUS_CURRENT)
	pi(GIT_STATUS_INDEX_NEW)
	pi(GIT_STATUS_INDEX_MODIFIED)
	pi(GIT_STATUS_INDEX_DELETED)
	pi(GIT_STATUS_INDEX_TYPECHANGE)
	pi(GIT_STATUS_INDEX_RENAMED)
	pi(GIT_STATUS_WT_NEW)
	pi(GIT_STATUS_WT_MODIFIED)
	pi(GIT_STATUS_WT_DELETED)
	pi(GIT_STATUS_WT_TYPECHANGE)
	pi(GIT_STATUS_WT_RENAMED)
	pi(GIT_STATUS_WT_UNREADABLE)
	pi(GIT_STATUS_IGNORED)
	pi(GIT_STATUS_CONFLICTED)
	*/
	
	error = git_status_foreach_ext(repo, &opts, gitprefix(collect_cb), NULL);
	if (error)
	{
		puts("an error has occured collecting status information");
		if (status_list) free(status_list);
		status_list = NULL;
		status_list_index = 0;
		return error;
	}
	if (nothing()) {
		puts("nothing to commit");
		status_list_index = 0;
		if (status_list) free(status_list);
		status_list = NULL;
		return 0;
	}
		
	
	gitprefix(show_branchST)(repo, FORMAT_LONG);
	
	
	// info collected, print it
	size_t maxi = git_status_list_entrycount(status);
	const git_status_entry *s;
	int header = 0, changes_in_index = 0, changed_in_workdir = 0, rm_in_workdir = 0;
	const char *old_path, *new_path;
	
	for (int i = 0; i < status_list_index; i++) {
		char * istatus = NULL;
		if (status_list[i].status == GIT_STATUS_CURRENT)
			continue;
		if (status_list[i].status & GIT_STATUS_WT_DELETED)
			rm_in_workdir = 1;
		if (status_list[i].status & GIT_STATUS_INDEX_NEW)
			istatus = "new file: ";
		if (status_list[i].status & GIT_STATUS_INDEX_MODIFIED)
			istatus = "modified: ";
		if (status_list[i].status & GIT_STATUS_INDEX_DELETED)
			istatus = "deleted:  ";
		if (status_list[i].status & GIT_STATUS_INDEX_RENAMED) {
			istatus = "renamed:  ";
			find_renamed_file(repo, status_list[i].path);
			for (int ii = 0; ii < maxi; ++ii) {
				s = git_status_byindex(status, ii);
				git_status_entry_infos(s, GIT_STATUS_INDEX_RENAMED);
			}
		}
		if (status_list[i].status & GIT_STATUS_INDEX_TYPECHANGE)
			istatus = "typechange:";
		if (istatus == NULL)
			continue;
		if (!header) {
			printf("# Changes to be committed:\n");
			printf("#   (use \"git reset HEAD <file>...\" to unstage)\n");
			printf("#\n");
			header = 1;
		}
		printf("#\t%s  %s\n", istatus, status_list[i].path);
	}
	
	if (header) {
		changes_in_index = 1;
		printf("#\n");
	}
	header = 0;
	
	for (int i = 0; i < status_list_index; i++) {
		char *wstatus = NULL;
		if (status_list[i].status & GIT_STATUS_WT_MODIFIED)
			wstatus = "modified: ";
		if (status_list[i].status & GIT_STATUS_WT_DELETED)
			wstatus = "deleted:  ";
		if (status_list[i].status & GIT_STATUS_WT_RENAMED) {
			wstatus = "renamed:  ";
			find_renamed_file(repo, status_list[i].path);
			for (int ii = 0; ii < maxi; ++ii) {
				s = git_status_byindex(status, ii);
				git_status_entry_infos(s, GIT_STATUS_WT_RENAMED);
			}
		}
		if (status_list[i].status & GIT_STATUS_WT_TYPECHANGE)
			wstatus = "typechange:";

		if (wstatus == NULL)
			continue;

		if (!header) {
			printf("# Changes not staged for commit:\n");
			printf("#   (use \"git add%s <file>...\" to update what will be committed)\n", rm_in_workdir ? "/rm" : "");
			printf("#   (use \"git checkout -- <file>...\" to discard changes in working directory)\n");
			printf("#\n");
			header = 1;
		}
		printf("#\t%s  %s\n", wstatus, status_list[i].path);
	}
	if (header) {
		changed_in_workdir = 1;
		printf("#\n");
	}
	header = 0;

	for (int i = 0; i < status_list_index; i++) {
		if (status_list[i].status == GIT_STATUS_WT_NEW) {
			if (!header) {
				printf("# Untracked files:\n");
				printf("#   (use \"git add <file>...\" to include in what will be committed)\n");
				printf("#\n");
				header = 1;
			}
			printf("#\t%s\n", status_list[i].path);
		}
	}
	header = 0;

	for (int i = 0; i < status_list_index; i++) {
		if (status_list[i].status == GIT_STATUS_IGNORED) {
			if (!header) {
				printf("# Ignored files:\n");
				printf("#   (use \"git add -f <file>...\" to include in what will be committed)\n");
				printf("#\n");
				header = 1;
			}
			printf("#\t%s\n", status_list[i].path);
		}
	}
	if (!changes_in_index && changed_in_workdir) printf("no changes added to commit (use \"git add\" and/or \"git commit -a\")\n");
	
	if (status_list) free(status_list);
	status_list = NULL;
	status_list_index = 0;
	return 0;
}

/**
 * This version of the output prefixes each path with two status
 * columns and shows submodule status information.
 */
void gitprefix(print_shortST)(git_repository *repo, git_status_list *status)
{
	size_t i, maxi = git_status_list_entrycount(status);
	const git_status_entry *s;
	char istatus, wstatus;
	const char *extra, *a, *b, *c;

	for (i = 0; i < maxi; ++i) {
		s = git_status_byindex(status, i);

		if (s->status == GIT_STATUS_CURRENT)
			continue;

		a = b = c = NULL;
		istatus = wstatus = ' ';
		extra = "";

		if (s->status & GIT_STATUS_INDEX_NEW)
			istatus = 'A';
		if (s->status & GIT_STATUS_INDEX_MODIFIED)
			istatus = 'M';
		if (s->status & GIT_STATUS_INDEX_DELETED)
			istatus = 'D';
		if (s->status & GIT_STATUS_INDEX_RENAMED)
			istatus = 'R';
		if (s->status & GIT_STATUS_INDEX_TYPECHANGE)
			istatus = 'T';

		if (s->status & GIT_STATUS_WT_NEW) {
			if (istatus == ' ')
				istatus = '?';
			wstatus = '?';
		}
		if (s->status & GIT_STATUS_WT_MODIFIED)
			wstatus = 'M';
		if (s->status & GIT_STATUS_WT_DELETED)
			wstatus = 'D';
		if (s->status & GIT_STATUS_WT_RENAMED)
			wstatus = 'R';
		if (s->status & GIT_STATUS_WT_TYPECHANGE)
			wstatus = 'T';

		if (s->status & GIT_STATUS_IGNORED) {
			istatus = '!';
			wstatus = '!';
		}

		if (istatus == '?' && wstatus == '?')
			continue;

		/**
		 * A commit in a tree is how submodules are stored, so
		 * let's go take a look at its status.
		 */
		if (s->index_to_workdir &&
			s->index_to_workdir->new_file.mode == GIT_FILEMODE_COMMIT)
		{
			unsigned int smstatus = 0;

			if (!git_submodule_status(&smstatus, repo, s->index_to_workdir->new_file.path,
						  GIT_SUBMODULE_IGNORE_UNSPECIFIED)) {
				if (smstatus & GIT_SUBMODULE_STATUS_WD_MODIFIED)
					extra = " (new commits)";
				else if (smstatus & GIT_SUBMODULE_STATUS_WD_INDEX_MODIFIED)
					extra = " (modified content)";
				else if (smstatus & GIT_SUBMODULE_STATUS_WD_WD_MODIFIED)
					extra = " (modified content)";
				else if (smstatus & GIT_SUBMODULE_STATUS_WD_UNTRACKED)
					extra = " (untracked content)";
			}
		}

		/**
		 * Now that we have all the information, format the output.
		 */

		if (s->head_to_index) {
			a = s->head_to_index->old_file.path;
			b = s->head_to_index->new_file.path;
		}
		if (s->index_to_workdir) {
			if (!a)
				a = s->index_to_workdir->old_file.path;
			if (!b)
				b = s->index_to_workdir->old_file.path;
			c = s->index_to_workdir->new_file.path;
		}

		if (istatus == 'R') {
			if (wstatus == 'R')
				printf("%c%c %s %s %s%s\n", istatus, wstatus, a, b, c, extra);
			else
				printf("%c%c %s %s%s\n", istatus, wstatus, a, b, extra);
		} else {
			if (wstatus == 'R')
				printf("%c%c %s %s%s\n", istatus, wstatus, a, c, extra);
			else
				printf("%c%c %s%s\n", istatus, wstatus, a, extra);
		}
	}

	for (i = 0; i < maxi; ++i) {
		s = git_status_byindex(status, i);

		if (s->status == GIT_STATUS_WT_NEW)
			printf("?? %s\n", s->index_to_workdir->old_file.path);
	}
}

int gitprefix(print_submodST)(git_submodule *sm, const char *name, void *payload)
{
	int *count = payload;
	(void)name;

	if (*count == 0)
		printf("# Submodules\n");
	(*count)++;

	printf("# - submodule '%s' at %s\n",
		git_submodule_name(sm), git_submodule_path(sm));

	return 0;
}

/**
 * Parse options that git's status command supports.
 */
void gitprefix(parse_optsST)(struct gitprefix(optsST) *o, int argc, char *argv[])
{
	struct args_info args = ARGS_INFO_INIT;

	for (args.pos = 1; args.pos < argc; ++args.pos) {
		char *a = argv[args.pos];

		if (a[0] != '-') {
			if (o->npaths < MAX_PATHSPEC)
				o->pathspec[o->npaths++] = a;
			else
				gitret(fatal("Example only supports a limited pathspec", NULL));
		}
		else if (!strcmp(a, "-s") || !strcmp(a, "--short"))
			o->format = FORMAT_SHORT;
		else if (!strcmp(a, "--long"))
			o->format = FORMAT_LONG;
		else if (!strcmp(a, "--porcelain"))
			o->format = FORMAT_PORCELAIN;
		else if (!strcmp(a, "-b") || !strcmp(a, "--branch"))
			o->showbranch = 1;
		else if (!strcmp(a, "-z")) {
			o->zterm = 1;
			if (o->format == FORMAT_DEFAULT)
				o->format = FORMAT_PORCELAIN;
		}
		else if (!strcmp(a, "--ignored"))
			o->statusopt.flags |= GIT_STATUS_OPT_INCLUDE_IGNORED;
		else if (!strcmp(a, "-uno") ||
				 !strcmp(a, "--untracked-files=no"))
			o->statusopt.flags &= ~GIT_STATUS_OPT_INCLUDE_UNTRACKED;
		else if (!strcmp(a, "-unormal") ||
				 !strcmp(a, "--untracked-files=normal"))
			o->statusopt.flags |= GIT_STATUS_OPT_INCLUDE_UNTRACKED;
		else if (!strcmp(a, "-uall") ||
				 !strcmp(a, "--untracked-files=all"))
			o->statusopt.flags |= GIT_STATUS_OPT_INCLUDE_UNTRACKED |
				GIT_STATUS_OPT_RECURSE_UNTRACKED_DIRS;
		else if (!strcmp(a, "--ignore-submodules=all"))
			o->statusopt.flags |= GIT_STATUS_OPT_EXCLUDE_SUBMODULES;
		else if (!strncmp(a, "--git-dir=", strlen("--git-dir=")))
			o->repodir = a + strlen("--git-dir=");
		else if (!strcmp(a, "--repeat"))
			o->repeat = 10;
		else if (match_int_arg(&o->repeat, &args, "--repeat", 0))
			/* okay */;
		else if (!strcmp(a, "--list-submodules"))
			o->showsubmod = 1;
		else
			check_lg2(-1, "Unsupported option", a);
	}

	if (o->format == FORMAT_DEFAULT)
		o->format = FORMAT_LONG;
	if (o->format == FORMAT_LONG)
		o->showbranch = 1;
	if (o->npaths > 0) {
		o->statusopt.pathspec.strings = o->pathspec;
		o->statusopt.pathspec.count   = o->npaths;
	}
}
