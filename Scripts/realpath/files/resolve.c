#include <libgen.h>
static char *
process_path_return (const char *fname, char * relative_to, int can_mode)
{
  char *can_fname = realpath_canon (fname, can_mode);
  char *can_relative_to = realpath_canon (relative_to, can_mode);
  if (!access(can_relative_to,F_OK)) {
  	if (isdir(can_relative_to) == false) {
  		can_relative_to=dirname_missing(can_relative_to);
  	}
  } else {
  	//does not exist, test if it is suffixed with a /
  	if (can_relative_to[strlen(can_relative_to)-1] != '/') {
  		printf("Warning: given directory MUST end in a /\nGiven directory: %s\nWarning: assuming \"%s\" is a directory\n", can_relative_to, basename(can_relative_to));
  	}
  }
  if (!can_fname)
    {
       error (0, errno, "%s", quotef (fname));
      return NULL;
    }
    
    if (!can_relative_to)
    {
       error (0, errno, "%s", quotef (fname));
      return NULL;
    }
    char * buf = malloc(PATH_MAX);
    relpath (can_fname, can_relative_to, buf, PATH_MAX);
	free(can_fname);
    free(can_relative_to);
    return buf;
}

char * resolve(char * from, char * to)
{
	return process_path_return(from, to, CAN_MISSING | CAN_NOLINKS);
}
