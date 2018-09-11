
#define touch(x) close(open(x,O_WRONLY | O_CREAT, DEFFILEMODE))

#define gitprefix(x) git_libgit_version_2_api_##x

#define gitprefix(x) git_libgit_version_2_api_##x


#define giterr(x) { printf("%s = %d (%s)\n", #x, x, giterr_last()?giterr_last()->message:"none"); }

#define giterror(...) { \
	printf("error: " __VA_ARGS__); \
	printf(" (%s)", giterr_last()?giterr_last()->message:"none"); \
	printf("\n"); \
	return -2; \
}

#define giterrornomessage(...) { \
	printf("error: " __VA_ARGS__); \
	printf("\n"); \
	return -2; \
}

#define giterrorn(...) { \
	printf("error: " __VA_ARGS__); \
	printf(" (%s)", giterr_last()?giterr_last()->message:"none"); \
	printf("\n"); \
	return NULL; \
}

#define gitret(x) { \
	int ret = x ; \
	if (ret) return ret; \
}

#define gitisnull(x) { \
	if (x == NULL) printf("%s is NULL\n", #x); \
	else printf("%s is not NULL\n", #x); \
}


#define gitdo(x) if (strcmp(argv[0], #x) == 0) { return gitprefix(x)(argc, argv); }

int match_macro(char * x, char * argv[]) {
	char * hardcoded_platform_specific_path_separator = "_";
	int i = 0;
	int matches = 0;
	for (char *tok = strtok(x, hardcoded_platform_specific_path_separator);tok; tok = strtok(NULL, hardcoded_platform_specific_path_separator)) {
		if (!argv[i]) {
			return 1;
		}
		if(strcmp(tok, argv[i]) == 0) matches = 0;
		else {
			matches = 1;
			break;
		} 
		i++;
	}
	return matches;
}

#define gitdo_(x) if (match_macro(#x, argv) == 0) { return gitprefix(x)(argc, argv); }
