#include <curl/curl.h>

// git curl create https://github.com/mgood7123/invalid.git

#include "callbacks/curl.h"

int gitprefix(curl_create)(char * url)
{
	url = fixurl(url);
	char * user = extractuser(url);
	char * password = NULL;
	char * repo = extractrepo(url);
	char * description = "";
	
	int postlen = strlen("{\"name\":\"\",\"description\":\"\"}")+strlen(repo)+strlen(description)+1;
	char * post = malloc(postlen);
	memset(post, 0, postlen);
	snprintf(post, postlen, "{\"name\":\"%s\",\"description\":\"%s\"}", repo, description);
	if (using_defined == false) {
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
	}
	else password = defined_password;
	int USERPWDLEN = strlen(user)+strlen(":")+strlen(password)+1;
	char * USERPWD = malloc(USERPWDLEN);
	memset(USERPWD,0,USERPWDLEN);
	snprintf(USERPWD, USERPWDLEN, "%s:%s", user, password);
	ps(post);
	pi(USERPWDLEN)
	pi(USERPWD[USERPWDLEN])
	ps(USERPWD);
	ps(password);
	
	struct MemoryStruct chunk;
	
	chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */
	chunk.size = 0;    /* no data at this point */
	
	CURL *curl;
	CURLcode res;
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "Dark Secret Ninja/1.0");
		curl_easy_setopt(curl, CURLOPT_URL, "https://api.github.com/user/repos");
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post);
		curl_easy_setopt(curl, CURLOPT_USERPWD, USERPWD);
		//curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
		res = curl_easy_perform(curl);
		long response_code;
		if(res != CURLE_OK) fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		else {
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
			/*
			 Now, our chunk.memory points to a memory block that is chunk.size
			 bytes big and contains the remote file.
			 
			 Do something nice with it!
			 */
			if (chunk.memory) ps(chunk.memory);
		}
		free(chunk.memory);
		if (response_code == 201L) printf("\ncreated server repo at %s\n", url);
		else printf("unknown error occurred: %li\n", response_code);
		curl_easy_cleanup(curl);
	}
	else puts("curl failed to initialize");
	free(post);
	if (using_defined == false) free(password);
	free(USERPWD);
	curl_global_cleanup();
	return 0;
}

int gitprefix(curl)(int argc, char * argv[]) {
	if (argc < 2) giterrornomessage("%s requires an additional command", argv[0]);
	if(strcmp(argv[1], "create") == 0) {
		if (argc < 3) giterrornomessage("%s requires a url", argv[1]);
		return gitprefix(curl_create)(argv[2]);
	}
	else giterrornomessage("%s is not a valid sub command of %s", argv[1], argv[0]);
}
