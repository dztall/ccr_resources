/*
 * libgit2 "add" example - shows how to modify the index
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

// https://gitirc.eu/git-add.html

#include <assert.h>

enum print_options {
	SKIP = 1,
	VERBOSE = 2,
	UPDATE = 4,
};

struct print_payload {
	enum print_options options;
	git_repository *repo;
};

/* Forward declarations for helpers */
int gitprefix(parse_optsA)(int *options, int *count, int argc, char *argv[]);
void gitprefix(init_array)(git_strarray *array, int argc, char **argv);

#include "callbacks/add.h"


int gitprefix(add) (int argc, char** argv)
{
	git_index_matched_path_cb matched_cb = &pmatched_cb;
	git_repository *repo = NULL;
	git_index *index;
	git_strarray array = {0};
	int options = 0, count = 0;
	struct print_payload payload = {0};

	pi(git_libgit2_features());
	pi(git_libgit2_init());

	gitret(gitprefix(parse_optsA)(&options, &count, argc, argv));

	gitprefix(init_array)(&array, argc-count, argv+count);

	gitopenrepo(&repo, NULL);
	
	if (git_repository_index(&index, repo)) {
		git_index_free(index);
		git_repository_free(repo);
		git_libgit2_shutdown();
		giterror("Could not open repository index");
	}

	payload.options = options;
	payload.repo = repo;

	git_index_add_all(index, &array, GIT_INDEX_ADD_DEFAULT, matched_cb, &payload);
	git_index_update_all(index, &array, matched_cb, &payload);

	git_index_write(index);
	git_index_free(index);
	git_repository_free(repo);

	git_libgit2_shutdown();

	return 0;
}

int add_all = 0;

void gitprefix(init_array) (git_strarray *array, int argc, char **argv)
{
	unsigned int i;

	array->count = argc;
	array->strings = malloc(sizeof(char*) * array->count);
	assert(array->strings!=NULL);
	if (add_all) {
		array->strings[0] = ".";
		return;
	}
	for(i=0; i<array->count; i++) {
		array->strings[i]=argv[i];
	}

	return;
}

int gitprefix(print_usageA) (void)
{
	fprintf(stderr, "usage: add [options] [--] file-spec [file-spec] [...]\n\n");
	fprintf(stderr, "\t-A, --all        add all\n");
	fprintf(stderr, "\t-n, --dry-run    dry run\n");
	fprintf(stderr, "\t-v, --verbose    be verbose\n");
	fprintf(stderr, "\t-u, --update     update tracked files\n");
	return -1;
}

int gitprefix(parse_optsA) (int *options, int *count, int argc, char *argv[])
{
	int i;

	for (i = 1; i < argc; ++i) {
		if (argv[i][0] != '-') {
			break;
		}
		else if(!strcmp(argv[i], "--all") || !strcmp(argv[i], "-A")) {
			add_all = 1;
			break;
		}
		else if(!strcmp(argv[i], "--verbose") || !strcmp(argv[i], "-v")) {
			*options |= VERBOSE;
		}
		else if(!strcmp(argv[i], "--dry-run") || !strcmp(argv[i], "-n")) {
			*options |= SKIP;
		}
		else if(!strcmp(argv[i], "--update") || !strcmp(argv[i], "-u")) {
			*options |= UPDATE;
		}
		else if(!strcmp(argv[i], "-h")) {
			return gitprefix(print_usageA)();
			break;
		}
		else if(!strcmp(argv[i], "--")) {
			i++;
			break;
		}
		else {
			fprintf(stderr, "Unsupported option %s.\n", argv[i]);
			return gitprefix(print_usageA)();
		}
	}
	if (argc<=i)
		return gitprefix(print_usageA)();

	*count = i;
	return 0;
}
