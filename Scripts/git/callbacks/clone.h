typedef struct progress_data {
	git_transfer_progress fetch_progress;
	size_t completed_steps;
	size_t total_steps;
	const char *path;
} progress_data;


static void print_progress(const progress_data *pd)
{
	int network_percent = pd->fetch_progress.total_objects > 0 ?
		(100*pd->fetch_progress.received_objects) / pd->fetch_progress.total_objects :
		0;
	int index_percent = pd->fetch_progress.total_objects > 0 ?
		(100*pd->fetch_progress.indexed_objects) / pd->fetch_progress.total_objects :
		0;

	int checkout_percent = pd->total_steps > 0
		? (100 * pd->completed_steps) / pd->total_steps
		: 0;

	if (pd->fetch_progress.total_objects && pd->fetch_progress.received_objects == pd->fetch_progress.total_objects) {
		if (!n1) {
			printf("Recieving objects: %3d%% (%d/%d)  | ", network_percent, pd->fetch_progress.received_objects, pd->fetch_progress.total_objects);
			str_humanise_bytes2(pd->fetch_progress.received_bytes);
			printf(", done.\n");
			n1 = 1;
		}
		if (pd->fetch_progress.total_deltas) {
			if (pd->fetch_progress.indexed_deltas == pd->fetch_progress.total_deltas && !n2) {
				printf("Resolving deltas %d/%d, done.\n", pd->fetch_progress.indexed_deltas, pd->fetch_progress.total_deltas);
				n2 = 1;
			}
			else if (pd->fetch_progress.indexed_deltas != pd->fetch_progress.total_deltas && n2) printf("Resolving deltas %d/%d\r", pd->fetch_progress.indexed_deltas, pd->fetch_progress.total_deltas);
		}
	} else {
		printf("Recieving objects: %3d%% (%d/%d)  | ", network_percent, pd->fetch_progress.received_objects, pd->fetch_progress.total_objects);
			str_humanise_bytes2(pd->fetch_progress.received_bytes);
			printf("   \r");
	}
}

static int sideband_progress(const char *str, int len, void *payload)
{
	(void)payload; // unused

	printf("remote: %.*s", len, str);
	fflush(stdout);
	return 0;
}

static int fetch_progress(const git_transfer_progress *stats, void *payload)
{
	progress_data *pd = (progress_data*)payload;
	pd->fetch_progress = *stats;
	print_progress(pd);
	return 0;
}
static void checkout_progress(const char *path, size_t cur, size_t tot, void *payload)
{
	progress_data *pd = (progress_data*)payload;
	pd->completed_steps = cur;
	pd->total_steps = tot;
	pd->path = path;
	print_progress(pd);
}
