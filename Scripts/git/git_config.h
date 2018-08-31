// hook to read from custom directory

#include "hooks/config.h"

git_global_config_directory = "CCR_DOCUMENTS_DIR";

char * cfg_var, *cfg_val;

int gitprefix(create_global) (void) {
	str_new(git_global_config_directory_default_path)
	str_insert_string(git_global_config_directory_default_path, git_global_config_directory_default_path.index, env__get(environ, git_global_config_directory));
	str_insert_string(git_global_config_directory_default_path, git_global_config_directory_default_path.index, "/.gitconfig");
	ps(git_global_config_directory_default_path.string)
	if (access(git_global_config_directory_default_path.string, F_OK)) {
		puts("create global config");
		touch(git_global_config_directory_default_path.string);
		if (access(git_global_config_directory_default_path.string, F_OK)) {
			puts("failed to create global config");
			str_free(git_global_config_directory_default_path);
			return -1;
		}
		str_free(git_global_config_directory_default_path);
	}
	return 0;
}

char * gitprefix(config_find_global) (void) {
	git_buf path = NULL;
	gitprefix(create_global)(); // if git_global_config_directory_default_path does not exist, we create it
	giterr(git_config_find_global(&path)) // file created, load it
	if (path) return NULL;
	return path.ptr; // file loaded
}

int gitprefix(config_new) (char * var, char * val) {
	ps(var)
	ps(val)
	git_config *cfg = NULL;
	giterr(git_config_open_default(&cfg))
	git_config *global_cfg = NULL;
	giterr(git_config_open_level(&global_cfg, cfg, GIT_CONFIG_LEVEL_GLOBAL));
	git_config_set_string(cfg, var, val);
	git_config_free(cfg); // returns void
	return 0;
}

int gitprefix(print_usageC) (void)
{
	fprintf(stderr, "usage: config [options] [--] file-spec [file-spec] [...]\n\n");
	fprintf(stderr, "\t-A, --all        add all\n");
	fprintf(stderr, "\t-n, --dry-run    dry run\n");
	fprintf(stderr, "\t-v, --verbose    be verbose\n");
	fprintf(stderr, "\t-u, --update     update tracked files\n");
	return -1;
}

int gitprefix(config) (int argc, char * argv[]) {
	int is_global;
	// process args
	//for (int i = 1; i< argc; i++) ps(argv[i])
	
	for (int i = 1; i< argc; i++) {
		//ps(argv[i])
		if (!strcmp(argv[i], "-h") || !strcmp(argv[i],"--help")) {
			return gitprefix(print_usageC)();
		}
		else if (!strcmp(argv[i], "--global")) {
			is_global = 1;
			pi(is_global)
		}
		else if ((argv[i])[0]== '-') {
			fprintf(stderr, "Unsupported option %s.\n", argv[i]);
			return gitprefix(print_usageC)();
		}
		else {
			//pi(i)
			//pi(argc)
			cfg_var = argv[i];
			i++;
			cfg_val = argv[i];
			
			ps(cfg_var)
			ps(cfg_val)
		}
	}
	
	giterr(git_libgit2_init());
	pi(is_global)
	if (is_global) {
		//char * path;
		//path = gitprefix(config_find_global)();
		//ps(path);
		gitprefix(config_new)(!cfg_var?"default":cfg_var, !cfg_val?"default":cfg_val);
		//if (!path) free(path);
	}
	giterr(git_libgit2_shutdown());
	return 0;
}
