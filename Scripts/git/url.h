
#define _GNU_SOURCE
int strcmp(const char *X, const char *Y)
{
    while(*X)
    {
    	// if characters differ or end of second string is reached
        if (*X != *Y)
            break;
		
		// move to next pair of characters
        X++;
        Y++;
    }

    // return the ASCII difference after converting char* to unsigned char*
    int ret = *(const unsigned char*)X - *(const unsigned char*)Y;
    #ifdef _GNU_SOURCE
    // gnu strcmp returns -1, 0, or 1, it never exceeds -1 or 1
    return ret>0?1:ret<0?-1:0;
    #else
    return ret;
    #endif
}
// cus strcmp gives false positives, use our own strcmp function
int urlmatch(void const *vp, size_t n, void const *vp2, size_t n2, int match_rel)
{
    int string_match = 0;
    unsigned char const *p = vp;
    unsigned char const *p2 = vp2;
    size_t matches=0;
    size_t pmatches=0;
    for (size_t i=0; i<n; i++) if (p[i] == p2[i]) matches++; else break;
    if (!matches) return -1;
    else if(matches != n2) {
    	if (match_rel) return -2;
    	else if (!match_rel) return -3;
    	else return -4;
    }
    else if (matches == n) return 0;
    else return 1;
}

int url(void const * p, void const * pp) { return urlmatch(p, strlen(p), pp, strlen(pp), 0); }
int urlp(void const * p, void const * pp) { return urlmatch(p, strlen(p), pp, strlen(pp), 1); }

char b[1024]; // this will get erased if recursively called, eg u = fix(a); fixurl(u);

/*
T78>        git_libgit_version_2_api_curl_create("https://github.com/mgood7123/git_implementation_test_push.git"); 
T78>         fixurl("https://github.com/mgood7123/git_implementation_test_push.git"); 
T78>          memset("https://github.com/mgood7123/git_implementation_test_push.git", 0, 1024); 
T78>           return 0x45932101; //from memset
T78>          url("", "http://www.github.com/"); 
T78>           strlen(0x45932101); 
*/

#define nc(x) case_##x == -1
#define yc(x) case_##x == 1

char * fixurl(char * broken_url) {
	if (url(broken_url, "https://github.com/") == 1) return broken_url;
	if (*b) memset(b,0,1024);
	int case_1 = url(broken_url, "http://www.github.com/");
	int case_2 = url(broken_url, "https://www.github.com/");
	int case_3 = url(broken_url, "http://github.com/");
	int case_5 = url(broken_url, "www.github.com/");
	// check for github.com/github.com/ explicitly
	int sub_case6_1 = urlp(broken_url, "github.com/github.com/");
	int sub_case6_2 = strcmp(broken_url, "github.com/github.com/");
	int case_6;
	
	if (sub_case6_2 == 1) {
		if (sub_case6_1 == 1) case_6 = 1;
		else if (sub_case6_1 == -2) {
			if (sub_case6_2 == -1) case_6 = 1;
			else if (sub_case6_2 == 1) case_6 = -1;
		}
	}
	else case_6 = sub_case6_1;
	int case_7 = strstr(broken_url, "/")==NULL?-1:1;
	if (yc(7)) {
		if(yc(1) || yc(2)) {
			snprintf(b, 1024, "https://%s", strstr(broken_url, "github.com/"));
			return b;
		}
		else if(yc(3)) {
			snprintf(b, 1024, "https://%s", strstr(broken_url, "github.com/"));
			return b;
		}
		else if (yc(5)) {
			snprintf(b, 1024, "https://%s", broken_url);
			return b;
		}
		else if (yc(6)) {
			
			snprintf(b, 1024, "https://%s", broken_url);
			return b;
		}
		else {
			snprintf(b, 1024, "https://github.com/%s", broken_url);
			return b;
		}
	}
	return broken_url;
}
