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
