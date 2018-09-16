
#define printoid(oid) { \
	char oidhex[GIT_OID_HEXSZ+1] = GIT_OID_HEX_ZERO; \
	git_oid_fmt(oidhex, oid); \
	printf("%s = [%s]\n", #oid, oidhex); \
}

void visit(git_commit * c) {
	size_t num_parents = git_commit_parentcount(c);
	printoid(git_commit_id(c));
	ps(git_commit_message(c));
	pi(num_parents);
}

void commit_reference_listing(git_repository *repo)
{
	git_strarray ref_list;
	unsigned i;

	printf("\n*Reference Listing*\n");
	
	git_reference_list(&ref_list, repo);

	for (i = 0; i < ref_list.count; ++i) {
		git_reference *ref;
		char oid_hex[GIT_OID_HEXSZ+1] = GIT_OID_HEX_ZERO;
		const char *refname;

		refname = ref_list.strings[i];
		git_reference_lookup(&ref, repo, refname);

		switch (git_reference_type(ref)) {
			case GIT_REF_OID:
				const git_oid *oid;
				oid = git_reference_target(ref);
				git_oid_fmt(oid_hex, oid);
				printf("%s [%s]\n", refname, oid_hex);
				break;

			case GIT_REF_SYMBOLIC:
				printf("%s => %s\n", refname, git_reference_symbolic_target(ref));
				break;
			default:
				fprintf(stderr, "Unexpected reference type\n");
				git_reference_free(ref);
				git_strarray_free(&ref_list);
				return -1;
		}

		git_reference_free(ref);
	}

	git_strarray_free(&ref_list);
}

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
		if (git_signature_new(&sig, "mgood7123","smallville7123@gmail.com",clock(),0) < 0) {
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
		puts("commit sucessfull");
		printoid(&commit_id);
	} else if (git_repository_head_unborn(repo) == 0) {
		git_oid parent_id;
		git_commit *parent;
		// Get HEAD as a commit object to use as the parent of the commit 
		puts("aquiring reference");
		giterr(git_reference_name_to_id(&parent_id, repo, "HEAD"));
		printoid(&parent_id);
		puts("looking up reference");
		giterr(git_commit_lookup(&parent, repo, &parent_id));
		puts("attemting to commit");
		giterr(git_commit_tree(&tree, parent));
		visit(parent);
		int ret = git_commit_create_v(&commit_id, repo, "HEAD", sig, sig, NULL, "-a", tree, 1, parent);
		free(parent);
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
		printoid(&commit_id);
	}
	
	/** Clean up so we don't leak memory. */

	git_tree_free(tree);
	git_signature_free(sig);
	commit_reference_listing(repo);
	git_repository_free(repo);
	git_libgit2_shutdown();
	return 0;
}
