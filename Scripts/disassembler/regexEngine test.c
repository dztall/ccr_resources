
#include "regexEngine.h"
#include "../Shell/builtins/clock.h"
#define dothis(what, times) {\
	for(int i = 0;i<times;i++) { what }; \
}
int main(void)
{
	regexEngine_Debug = true;
	regexEngine_max_bit_length = 32;
	regexEngine_bit_start = 31;
	char * str = "12345670000000000000000000080000";
	/*
	timefunc(
	dothis(
	regexEngine("31-28,1234 not 1111,27-25,00x,4,-",str);
	, 2454
	)
	);
	*/
	ps(str)
	pi(strlen(str))
	pi(regexEngine("27-25,..7", str))
	pi(regexEngine("31-28,1..1", str))
	/*
	pi(regexEngine("31-28,not 1111,27-25,00x,4,-", str))
	pi(regexEngine("4,-", str))
	pi(regexEngine("31-28,1..1", str))
	pi(regexEngine("31-28,1..4 not 1.34", str))
	pi(regexEngine("31-28,1..4 not 1.24", str))
	pi(regexEngine("31-28,1..4 not 1324", str))
	pi(regexEngine("31-28,1..4 not 4321", str))
	*/
	return 0;
}

