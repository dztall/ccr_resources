#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <libgen.h>
#include <unistd.h>
#include <string.h>


int bcmpcq_(void const *vp, size_t n, void const *vp2, size_t n2)
{
    int string_match = 0;
    unsigned char const *p = vp;
    unsigned char const *p2 = vp2;
    int matches=0,i=0;
    for (; i<n; i++) if (p[i] == p2[i]) matches++; else break;
    if (matches == 0 || i < n) return -1;
    else return 0;
}

int bytecmpcq(void const * p, void const * pp) { return bcmpcq_(p, strlen(p), pp, strlen(pp)); }

char * unknown(int type) {
	char unknown[10+16];
	sprintf(unknown, "unknown (%d)", type);
	return unknown;
}

char * __gettype (int type) {
	if (type==8) return "file";
	else if (type==4) return "folder";
	else return unknown(type);
}
struct fileinfo {
	char * name;
	char * type;
} fileinfo[9999];

const char * find(const char * file, const char * extention) {
	DIR *pDir;
	struct dirent *ent;
	int found;
	pDir = opendir(dirname(strdup(file)));
	if (pDir)
	{
		while((ent = readdir(pDir)) != NULL) {
			if (bytecmpcq(file, ent->d_name) == 0) {
				fileinfo[found].name = strdup(ent->d_name);
				fileinfo[found].type = strdup(__gettype(ent->d_type));
				printf("%s : %s (found %d)\n", fileinfo[found].name, fileinfo[found].type, found);
				printf("if fileinfo[%d].name = %s\n", found, fileinfo[found].name);
				found++;
			}
			printf("for fileinfo[0].name = %s\n", fileinfo[0].name);
			printf("for fileinfo[1].name = %s\n", fileinfo[1].name);
		}
		closedir(pDir);
	}
	else {
		printf("Access to %s was denied\n", file);
		return "NO_PERM";
	}
	printf("fileinfo[0].name = %s\n", fileinfo[0].name);
	printf("fileinfo[1].name = %s\n", fileinfo[1].name);
	if (found == 1 && bytecmpcq("file", fileinfo[0].type) == 0) {
		return fileinfo[0].name;
	}
	else if (found > 1) {
		// there is more than one file of the desired name, check for a file extention if given
		char * filefull = filefull = strdup(file);
		strcat(filefull, extention);
		for (int i = 0;i<found;i++) {
			printf("comparing %s with %s (id %d, found %d)\n", filefull, fileinfo[i].name, i, found);
			printf("for fileinfo[%d].name = %s\n", i, fileinfo[i].name);
			if (bytecmpcq(filefull, fileinfo[i].name) == 0 && bytecmpcq("file", fileinfo[i].type) == 0)
				return fileinfo[i].name;
			usleep(350);
		}
	}
	printf("%s could not be found", file);
	return "NULL";
}

int main()
{
	
	printf("getenv(\"CCR_RESOURCE_DIR\") = %s\n", getenv("CCR_RESOURCE_DIR"));
	find("wrapperfile", ".c");
	return 0;
}
