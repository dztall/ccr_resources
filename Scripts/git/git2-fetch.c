#include <git2.h>
#include <stdio.h>

#define REPOSITORY_DIR "Repository"
#define REMOTE_NAME    "origin"

void print_error()
{
    const git_error * last_error = giterr_last();
    printf("Error: %s\n", last_error->message);
}

int main (int argc, char ** argv)
{
    git_repository * repo = NULL;
    git_remote *   remote = NULL;
    const git_transfer_progress * stats;
    
    /* First, open the repository. */
    printf("Opening '%s'...\n", REPOSITORY_DIR);
    if(git_repository_open(&repo, REPOSITORY_DIR))
        goto error;
    
    /* Fetch the specified remote for the repository. */
    printf("Loading remote '%s'...\n", REMOTE_NAME);
    if(git_remote_load(&remote, repo, REMOTE_NAME))
        goto error;
    
    /* Connect to the remote. */
    printf("Connecting to remote...\n");
    if(git_remote_connect(remote, GIT_DIRECTION_FETCH))
        goto error;
    
    /* We're connected - now fetch the data. */
    printf("Downloading data from remote...\n");
    if(git_remote_download(remote, NULL, NULL))
        goto error;
    
    /* All operations succeeded, display stats and jump to done. */
    stats = git_remote_stats(remote);
    printf("All operations completed - %d objects received\n", stats->received_objects);
    goto done;
    
error:
    
    /* Display a description of the error. */
    print_error();
    
done:
    
    /* Disconnect and free all allocated structures. */
    if(remote)
    {
        if(git_remote_connected(remote))
            git_remote_disconnect(remote);
        git_remote_free(remote);
    }
    
    if(repo)
        git_repository_free(repo);
    
    return 0;
}
