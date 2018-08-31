


// these are unprofessional with minimal formatting

	
/*
The callback settings structure

Set the callbacks to be called by the remote when informing the user about the progress of the network operations.

unsigned int	version
	
git_transport_message_cb	sideband_progress
Textual progress from the remote. Text send over the progress side-band will be passed to this function (this is the 'counting objects' output).
	
int (*)(git_remote_completion_type, void *)	completion
Completion is called when different parts of the download process are done (currently unused).
	
git_cred_acquire_cb	credentials
This will be called if the remote host requires authentication in order to connect to it. Returning GIT_PASSTHROUGH will make libgit2 behave as though this field isn't set.
	
git_transport_certificate_check_cb	certificate_check
If cert verification fails, this will be called to let the user make the final decision of whether to allow the connection to proceed. Returns 0 to allow the connection or a negative value to indicate an error.
	
git_transfer_progress_cb	transfer_progress
During the download of new data, this will be regularly called with the current count of progress done by the indexer.
	
int (*)(const char *, const git_oid *, const git_oid *, void *)	update_tips
Each time a reference is updated locally, this function will be called with information about it.
	
git_packbuilder_progress	pack_progress
Function to call with progress information during pack building. Be aware that this is called inline with pack building operations, so performance may be affected.
	
git_push_transfer_progress	push_transfer_progress
Function to call with progress information during the upload portion of a push. Be aware that this is called inline with pack building operations, so performance may be affected.
	
git_push_update_reference_cb	push_update_reference
See documentation of git_push_update_reference_cb
	
git_push_negotiation	push_negotiation
Called once between the negotiation step and the upload. It provides information about what updates will be performed.
	
git_transport_cb	transport
Create the transport to use for this operation. Leave NULL to auto-detect.
	
void *	payload
This will be passed to each of the callbacks in this struct as the last parameter.

	
	options.callbacks.sideband_progress = gitprefix(git_transport_message_cb);
	options.callbacks.credentials = cred_acquire_cb;
	options.callbacks.certificate_check = gitprefix(git_transport_certificate_check_cb);
	options.callbacks.transfer_progress = gitprefix(git_transfer_progress_cb);
	options.callbacks.update_tips = gitprefix(git_remote_update_tips);
	options.callbacks.pack_progress = gitprefix(git_packbuilder_progress);
	options.callbacks.push_transfer_progress = gitprefix(git_push_transfer_progress);
	options.callbacks.push_update_reference = gitprefix(git_push_update_reference_cb);
    options.callbacks.push_negotiation = gitprefix(git_push_negotiation);
	options.callbacks.transport = gitprefix(git_transport_cb);
*/


int gitprefix(git_transport_message_cb) (const char *str, int len, void *payload) {
	CURRENT_FUNCTION
	// Type for messages delivered by the transport. Return a negative value to cancel the network operation.
	pi(len)
	if (len) ps(str)
	return 0;
}

int gitprefix(git_transport_certificate_check_cb) (git_cert *cert, int valid, const char *host, void *payload) {
	CURRENT_FUNCTION
	pi(valid)
	ps(host)
	return 0;
}

int gitprefix(git_transfer_progress_cb) (const git_transfer_progress *stats, void *payload) {
	CURRENT_FUNCTION
	/*
	Type for progress callbacks during indexing. Return a value less than zero to cancel the transfer.

	const git_transfer_progress *	stats	Structure containing information about the state of the transfer
void *	payload	Payload provided by caller
	*/
	return 0;
}

int gitprefix(git_remote_update_tips) (git_remote *remote, const git_remote_callbacks *callbacks, int update_fetchhead, git_remote_autotag_option_t download_tags, const char *reflog_message) {
	CURRENT_FUNCTION
	return 0;
}

int gitprefix(git_packbuilder_progress) (int stage, uint32_t current, uint32_t total, void *payload) {
	CURRENT_FUNCTION
	return 0;
}

int gitprefix(git_push_transfer_progress) (unsigned int current, unsigned int total, size_t bytes, void *payload) {
	CURRENT_FUNCTION
	pu(current)
	pu(total)
	psize_t(bytes)
	return 0;
}

int gitprefix(git_push_update_reference_cb) (const char *refname, const char *status, void *data) {
	CURRENT_FUNCTION
	// Called for each updated reference on push. If status is not NULL, the update was rejected by the remote server and status contains the reason given.
	ps(refname)
	if (status) if (*status) ps(status)
	return 0;
}

int gitprefix(git_push_negotiation) (const git_push_update **updates, size_t len, void *payload)
{
	CURRENT_FUNCTION
	pi(len)
	if (len) ps(*updates)
	return 0;
}

int gitprefix(git_transport_cb)(git_transport **out, git_remote *owner, void *param) {
	CURRENT_FUNCTION
	return 0;
}
