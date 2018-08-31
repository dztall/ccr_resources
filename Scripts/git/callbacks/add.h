int pmatched_cb(const char *path, const char *matched_pathspec, void *payload)
{
	puts("called");
	struct print_payload p = *(struct print_payload*)(payload);
	int ret;
	unsigned status;
	(void)matched_pathspec;

	if (git_status_file(&status, p.repo, path)) {
		return -1;
	}

	if (status & GIT_STATUS_WT_MODIFIED || status & GIT_STATUS_WT_NEW) {
		printf("add '%s'\n", path);
		ret = 0;
	} else {
		ret = 1;
	}

	if(p.options & SKIP) {
		ret = 1;
	}
	
	return ret;
}