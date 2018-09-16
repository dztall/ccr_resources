#pragma once
#ifdef __CPP__

typedef char *va_list;

inline char *__va_aligned__2(char *p, int align)
{
	int alignLocal = 8;
	long long ll=(long long)p;
	while(ll%alignLocal!=0)
		ll++;
	return (char *)ll;
}

#define va_start(ap, param) (ap) = ((char *)&param) + sizeof(param)
#define va_end(ap) (ap)
#define va_arg(ap, type) ((ap) = __va_aligned__2((ap), sizeof(type)*2), (ap) += sizeof(type)*2, *(type *)((ap) - (sizeof(type)*2)))
#define va_copy(dest, src)  (dest) = (src);

#else
#include <stdarg.h>
#endif
