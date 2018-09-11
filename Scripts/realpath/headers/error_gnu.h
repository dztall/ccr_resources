# define mbsrtowcs __mbsrtowcs
# define USE_UNLOCKED_IO 0
# define _GL_ATTRIBUTE_FORMAT_PRINTF(a, b)
# define _GL_ARG_NONNULL(a)
#define print_errno_message(e) puts(strerror(e))
#define flush_stdout() fflush(stdout)
#define program_name "program_name"
int error_message_count = 0;
#include <stdarg.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
static void _GL_ATTRIBUTE_FORMAT_PRINTF (3, 0) _GL_ARG_NONNULL ((3))
error_tail (int status, int errnum, const char *message, va_list args)
{
    vfprintf (stderr, message, args);
  va_end (args);

  ++error_message_count;
  if (errnum)
    print_errno_message (errnum);
  putc ('\n', stderr);
  fflush (stderr);
  if (status)
    exit (status);
}


/* Print the program name and error message MESSAGE, which is a printf-style
   format string with optional args.
   If ERRNUM is nonzero, print its corresponding system error message.
   Exit with status STATUS if it is nonzero.  */
void
error (int status, int errnum, const char *message, ...)
{
  va_list args;
  flush_stdout ();
  fprintf (stderr, "%s: ", program_name);
  va_start (args, message);
  error_tail (status, errnum, message, args);
}
