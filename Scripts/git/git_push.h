#include "callbacks/push.h"

int gitprefix(push1) (char * dir, char * from, char * to)
{
	ps(from)
	ps(to)
    git_repository* repo;
    git_push* push;
    bool cred_acquire_called;
    git_remote_callbacks callbacks = GIT_REMOTE_CALLBACKS_INIT;
    

	gitopenrepo(&repo, dir);
	
	// get the remote.
	git_remote* remote = NULL;
	if (git_remote_lookup( &remote, repo, from)) {
		git_remote_free(remote);
		giterror("could not look up remote \"%s\"", from);
	}
	
	// connect to remote
	callbacks.credentials = cred_acquire_cb;
	
	if (git_remote_connect(remote, GIT_DIRECTION_PUSH, &callbacks, NULL, NULL)) {
		git_remote_free(remote);
		giterror("could not connect to remote \"%s\", is it possible you forgot to add a URL to it? ( remote add %s <URL> ), error reason: ", from, from);
	}
	
	// add a push refspec
	char * ref = "refs/heads/";
	int pathlen = ( strlen(ref) *2 ) + ( strlen(to) *2 ) + 2;
	char * path = malloc(pathlen);
	snprintf(path, pathlen, "%s%s:%s%s", ref, to, ref, to);
	if (git_remote_add_push( repo, from, path)) {
		git_remote_free(remote);
		free(path);
		giterror("could not add push to remote \"%s\"", from);
	}
	free(path);
	
	// configure options
	git_push_options options;
	if (git_push_init_options( &options, GIT_PUSH_OPTIONS_VERSION )) {
		git_remote_free(remote);
		giterror("could not configure options for remote \"%s\"", from);
	}

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
	
	// do the push
	if (git_remote_upload( remote, NULL, &options )) {
		git_remote_free(remote);
		giterror("could not upload from remote \"%s\" to remote \"%s\"", from, to);
	}
	
	git_remote_free( remote );
	return true;
}

int gitprefix(push) (int argc, char * argv[]) {
	int err;
	giterr(git_libgit2_init());
	err = gitprefix(push1) (NULL, argv[1], argv[2]);
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
	return err;
}
