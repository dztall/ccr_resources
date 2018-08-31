struct collectlist {
	const char * path;
	git_status_t status;
	void * payload;
} *status_list;

int status_list_index = 0;

static int gitprefix(collect_cb)(const char *path, git_status_t status, void *payload)
{
	struct list * p = realloc(status_list, sizeof(*status_list)*(status_list_index+1));
	if (p == NULL) {
		puts("failed to reallocate list");
		return 1;
	}
	status_list = p;
	status_list[status_list_index].path = path;
	status_list[status_list_index].status = status;
	status_list[status_list_index].payload = payload;
	status_list_index++;
	return 0;
}
