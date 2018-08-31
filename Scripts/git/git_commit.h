


int gitprefix(commit) (int argc, char * argv[]) {
	git_repository *repo;
	git_signature *sig;
	git_index *index;
	git_oid tree_id, commit_id;
	git_tree *tree;
	
	pi(git_libgit2_init());

	if (git_repository_open(&repo, ".")) {
		git_libgit2_shutdown();
		giterror("Could not open repository");
	}
	
	/** First use the config to initialize a commit signature for the user. */
		
	if (git_signature_default(&sig, repo) < 0) {
		if (git_signature_new(&sig, "mgood7123","smallville7123@gmail.com",0,0) < 0) {
			git_signature_free(sig);
			git_repository_free(repo);
			git_libgit2_shutdown();
			giterror("Unable to create a commit signature.\n%s",
		      "Perhaps 'user.name' and 'user.email' are not set");
		}
	}

	/* Now let's create an empty tree for this commit */

	if (git_repository_index(&index, repo) < 0) {
		git_index_free(index);
		git_signature_free(sig);
		git_repository_free(repo);
		git_libgit2_shutdown();
		giterror("Could not open repository index", NULL);
	}

	/**
	 * Outside of this example, you could call git_index_add_bypath()
	 * here to put actual files into the index.  For our purposes, we'll
	 * leave it empty for now.
	 */

	if (git_index_write_tree(&tree_id, index) < 0) {
		git_index_free(index);
		git_tree_free(tree);
		git_signature_free(sig);
		git_repository_free(repo);
		git_libgit2_shutdown();
		giterror("Unable to write initial tree from index", NULL);
	}

	git_index_free(index);
	
	pi(git_repository_head_unborn(repo))
	if(git_repository_head_unborn(repo) == 1) {
		puts("looking up tree");
		if (git_tree_lookup(&tree, repo, &tree_id) < 0) {
			git_tree_free(tree);
			git_signature_free(sig);
			git_repository_free(repo);
			git_libgit2_shutdown();
			giterror("Could not look up initial tree", NULL);
		}
	
		/**
		 * Ready to create the initial commit.
		 *
		 * Normally creating a commit would involve looking up the current
		 * HEAD commit and making that be the parent of the initial commit,
		 * but here this is the first commit so there will be no parent.
		 */
		
		puts("attemting to commit");
		int ret = git_commit_create_v(&commit_id, repo, "HEAD", sig, sig, NULL, "Initial commit", tree, 0);
		if (ret < 0) {
			git_tree_free(tree);
			git_signature_free(sig);
			git_repository_free(repo);
			git_libgit2_shutdown();
			giterror("Could not create the initial commit (%d)", ret);
		}
	} else if (git_repository_head_unborn(repo) == 0) {
		git_oid parent_id;
		git_commit *parent;
		git_commit *parent2;
		// Get HEAD as a commit object to use as the parent of the commit 
		puts("aquiring reference");
		giterr(git_reference_name_to_id(&parent_id, repo, "HEAD"));
		/*
		puts("looking up reference");
		giterr(git_commit_lookup(&parent, repo, &parent_id));
		puts("attemting to commit");
		giterr(git_commit_tree(&tree, parent));
		//int ret = git_commit_create_v(&commit_id, repo, "HEAD", sig, sig, NULL, "-a", tree, 1, parent, NULL);
		*/
		/* Setup our parent commits */
		git_commit **parents = calloc(2, sizeof(git_commit *));
		giterr(git_reference_peel((git_object **)&parents[0], &parent_id, GIT_OBJ_COMMIT));
		puts("looking up commit");
		giterr(git_commit_lookup(&parents[1], repo, &parent_id));
		puts("attemting to commit");
		int ret = git_commit_create(&commit_id, repo, "HEAD", sig, sig, NULL, "-a", tree, 2, (const git_commit **)parents);
		free(parents);
	
		//int git_commit_parent(git_commit **out, const git_commit *commit, unsigned int n);
		//int ret = git_commit_parent(&parent2, parent, 0);
		giterr(ret);
		if (ret < 0) {
			git_tree_free(tree);
			git_repository_free(repo);
			git_libgit2_shutdown();
			giterror("Could not create the commit (%d)", ret);
		}
		puts("commit sucessfull");
		
	}
	
	/** Clean up so we don't leak memory. */

	git_tree_free(tree);
	git_signature_free(sig);
	git_repository_free(repo);
	git_libgit2_shutdown();
	return 0;
}

int gitprefix(commit2) (int argc, char * argv[]) {
	git_repository *repo;
	git_signature *sig;
	git_index *index;
	git_oid tree_id, commit_id;
	git_tree *tree = NULL;
	
	pi(git_libgit2_init());

	if (git_repository_open(&repo, ".")) {
		git_libgit2_shutdown();
		giterror("Could not open repository");
	}
	
	/** First use the config to initialize a commit signature for the user. */
		
	if (git_signature_default(&sig, repo) < 0) {
		if (git_signature_new(&sig, "mgood7123","smallville7123@gmail.com",0,0) < 0) {
			git_signature_free(sig);
			git_repository_free(repo);
			git_libgit2_shutdown();
			giterror("Unable to create a commit signature.\n%s",
		      "Perhaps 'user.name' and 'user.email' are not set");
		}
	}

	pi(git_repository_head_unborn(repo))
	if(git_repository_head_unborn(repo) == 1) {
		/* Now let's create an empty tree for this commit */

		if (git_repository_index(&index, repo) < 0) {
			git_index_free(index);
			git_signature_free(sig);
			git_repository_free(repo);
			git_libgit2_shutdown();
			giterror("Could not open repository index", NULL);
		}
	
		/**
		 * Outside of this example, you could call git_index_add_bypath()
		 * here to put actual files into the index.  For our purposes, we'll
		 * leave it empty for now.
		 */
	
		if (git_index_write_tree(&tree_id, index) < 0) {
			git_index_free(index);
			git_tree_free(tree);
			git_signature_free(sig);
			git_repository_free(repo);
			git_libgit2_shutdown();
			giterror("Unable to write initial tree from index", NULL);
		}
	
		git_index_free(index);
		
		puts("looking up tree");
		if (git_tree_lookup(&tree, repo, &tree_id) < 0) {
			git_tree_free(tree);
			git_signature_free(sig);
			git_repository_free(repo);
			git_libgit2_shutdown();
			giterror("Could not look up initial tree", NULL);
		}
	
		/**
		 * Ready to create the initial commit.
		 *
		 * Normally creating a commit would involve looking up the current
		 * HEAD commit and making that be the parent of the initial commit,
		 * but here this is the first commit so there will be no parent.
		 */
		
		puts("attemting to commit");
		int ret = git_commit_create_v(&commit_id, repo, "HEAD", sig, sig, NULL, "Initial commit", tree, 0);
		if (ret < 0) {
			git_tree_free(tree);
			git_signature_free(sig);
			git_repository_free(repo);
			git_libgit2_shutdown();
			giterror("Could not create the initial commit (%d)", ret);
		}
	} else if (git_repository_head_unborn(repo) == 0) {
		/* Now let's create an empty tree for this commit */
		
		if (git_repository_index(&index, repo) < 0) {
			git_index_free(index);
			git_signature_free(sig);
			git_repository_free(repo);
			git_libgit2_shutdown();
			giterror("Could not open repository index", NULL);
		}
	
		/**
		 * Outside of this example, you could call git_index_add_bypath()
		 * here to put actual files into the index.  For our purposes, we'll
		 * leave it empty for now.
		 */
		
		/* Overwrite the index contents with those of a tree */
		giterr(git_revparse_single((git_object**)&tree, repo, "HEAD~^{tree}"));
		giterr(git_index_read_tree(index, tree));
		
		/* Write the index contents to the ODB as a tree */
		giterr(git_index_write_tree(&tree_id, index));
		
		/* In-memory indexes can write trees to any repo */
		giterr(git_index_write_tree_to(&tree_id, index, repo));
	
		git_index_free(index);
		
		git_oid parent_id;
		git_commit *parent;
		git_commit *parent2;
		// Get HEAD as a commit object to use as the parent of the commit 
		puts("aquiring reference");
		giterr(git_reference_name_to_id(&parent_id, repo, "HEAD"));
		puts("looking up reference");
		giterr(git_commit_lookup(&parent, repo, &parent_id));
		puts("attemting to commit");
		giterr(git_commit_tree(&tree, parent));
		int ret = git_commit_create_v(&commit_id, repo, "HEAD", sig, sig, NULL, "-a", tree, 1, parent, NULL);
		//int git_commit_parent(git_commit **out, const git_commit *commit, unsigned int n);
		//int ret = git_commit_parent(&parent2, parent, 0);
		giterr(ret);
		if (ret < 0) {
			git_tree_free(tree);
			git_repository_free(repo);
			git_libgit2_shutdown();
			giterror("Could not create the commit (%d)", ret);
		}
		puts("commit sucessfull");
		
	}
	
	/** Clean up so we don't leak memory. */

	git_tree_free(tree);
	git_signature_free(sig);
	git_repository_free(repo);
	git_libgit2_shutdown();
	return 0;
}
