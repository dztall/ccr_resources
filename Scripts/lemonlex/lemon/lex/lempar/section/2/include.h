// line 69
#if LEMONEX
#define LX_CAPBUF_CHUNKSIZE 128
struct lxToken{
  char* buf;
  int buflen;
  int caplen;
  int row;
  int col;
  const char* filename;
};
#endif /* LEMONEX */
