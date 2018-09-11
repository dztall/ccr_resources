char * extractuser(char * url) {
	char * a = strstr(strstr(strdup(url),"github.com/"),"/");
	strrev(a);
	a = strstr(a, "/");
	strrev(a);
	a++;
	a[strlen(a)-1] = 0;
	return a;
}

char * extractrepo(char * url) {
	char * b = basename(url);
	if (strcmp(b+(strlen(b)-4), ".git") == 0) memset(b+strlen(b)-4, 0, 4);
	return b;
}

char *username = NULL, *password = NULL;

int cred_acquire_cb(git_cred **out,
		const char * (url),
		const char * (username_from_url),
		unsigned int (allowed_types),
		void * (payload))
{
	if (url) ps(url)
	if (username_from_url) ps(username_from_url)
	if (allowed_types) pi(allowed_types)
	int error;
	
	// we could aquire the username from the url, but there are cases where a user is allowed to push to a repo they do now own, in which they probably do not know that repo's password but are allowed to use there own username and password
	
	if (!using_defined) {
		if (!username) {
			int usernamelen = 0;
			while (usernamelen <2) {
				if (usernamelen == 1) puts("Username cannot be empty");
				if (usernamelen < 0) {
					fprintf(stderr, "Unable to read Username: %s\n", strerror(errno));
					return -1;
				}
				printf("Username: ");
				usernamelen = getline_stdin(&username);
			}
		}
		if (!password) {
			int passwordlen = 0;
			while (passwordlen <2) {
				if (passwordlen == 1) puts("Password cannot be empty");
				if (passwordlen < 0) {
					fprintf(stderr, "Unable to read Password: %s\n", strerror(errno));
					return -1;
				}
				printf("Password: ");
				passwordlen = getline_stdin(&password);
			}
		}
	} else {
		printf("using predefined username and password\n");
		username = defined_username;
		password = defined_password;
	}

	if (git_cred_userpass_plaintext_new(out, username, password)) {
		giterror("could not process credentials");
	}

	return 0;
}
