// line 22
#define LEMONEX 1

// line 39
#ifdef LEMONEX
    #include <errno.h>
#endif

// line 46
#ifdef LEMONEX
    #ifndef LEMONEX_DBG
        #define LEMONEX_DBG 0
    #endif
#endif

struct pstate;
struct lemon;
#include <stdbool.h>
#include "../../../../Shell/builtins/regex_str.h"
#include "../../../../Shell/builtins/env.h"
#include "../../../../Shell/builtins/printfmacro.h"
char ** x_e = NULL;
int x_e_idx = 0;

void x_e_free(void) {
	  if (env__size(x_e)) env__free(x_e);
}
