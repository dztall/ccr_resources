// line 1264
#if LEMONEX
/* The lexer code */
%%

/* The regex actions */
%%
#define LX_ACTION(s) lx_state_action_##s(lxpLexer)

/* The main lexer */
int ParseRead(
  void *yyp,
#if !ParseLX_INTEGRATEDMODE
  void *yyl,
#endif
  char *buf,
  char* buf_end,
  int is_final      /* 1 if this is final buffer in input stream */
  ParseARG_PDECL               /* Optional %extra_argument parameter */
){
  yyParser *yypParser = (yyParser*)(yyp);
#if ParseLX_INTEGRATEDMODE
  lxLexer *lxpLexer = yypParser->lxpLexer;
#else
  lxLexer *lxpLexer = (lxLexer*)(yyl);
#endif
  char* curr_pos;
  int curr_len;
  char* p = buf;
  int ch = 0;

%%

  return 0;
}

#ifndef NDEBUG
#define LX_DEBUG(t)
#else
#define LX_DEBUG(t) ,t
#endif

/* Helper function to allocate lexer and parser */
int lx_alloc_parser(
  void** pyyp
  ,void** plxp
  ,const char *filename
  ,const char* dbgpfx
){
  *pyyp = ParseAlloc(malloc);
  if(*pyyp == 0) {
    printf("unable to allocate parser\n");
    return 1;
  }

#if ParseLX_INTEGRATEDMODE
  ((struct yyParser*)(*pyyp))->lxpLexer->filename = filename;
#else
  *plxp = ParseLexerAlloc(malloc);
  if(*plxp == 0) {
    printf("unable to allocate lexer\n");
    ParseFree(*pyyp, free);
    return 1;
  }
  ((struct lxLexer*)(*plxp))->filename = filename;
#endif

#if LEMONEX_DBGLVL>=1
  if(dbgpfx != 0) {
    ParseTrace(stdout, (char*)dbgpfx);
  }
#endif
  return 0;
}

/* Helper function to free lexer and parser */
int lx_free_parser(
  void** pyyp
  ,void** plxp
){
#if !ParseLX_INTEGRATEDMODE
  if(*plxp != 0){
    ParseLexerFree(*plxp, free);
    *plxp = 0;
  }
#endif
  if(*pyyp != 0){
    ParseFree(*pyyp, free);
    *pyyp = 0;
  }
  return 0;
}

/* Helper function to read and parse an in-memory string */
int ParseReadString(
  char *buf
  ,const char *filename
  ,const char* dbgpfx
  ParseARG_PDECL               /* Optional %extra_argument parameter */
){
  void *yyp = 0;
  void *lxp = 0;
  if(lx_alloc_parser(&yyp, &lxp, filename, dbgpfx) != 0){
    return 1;
  }

  char *buf_end = buf;
  while(*buf_end != 0) ++buf_end;
#if ParseLX_INTEGRATEDMODE
  int rc = ParseRead(yyp, buf, buf_end, 1 ParseARG_VNAME);
#else
  int rc = ParseRead(yyp, lxp, buf, buf_end, 1 ParseARG_VNAME);
#endif
  if(rc < 0){
    printf("error in string:%d\n", rc);
    lx_free_parser(&yyp, &lxp);
    return 1;
  }
  lx_free_parser(&yyp, &lxp);
  return 0;
}

/* Helper function to read and parse a file */
int ParseReadFile(
  const char *filename
  ,const char* dbgpfx
  ParseARG_PDECL               /* Optional %extra_argument parameter */
){
  void *yyp = 0;
  void *lxp = 0;
  if(lx_alloc_parser(&yyp, &lxp, filename, dbgpfx) != 0){
    return 1;
  }

#ifdef _WIN32
  FILE* fp = 0;
  errno_t err = fopen_s(&fp, filename, "rb");
  if (err != 0) {
#else
  FILE* fp = fopen(filename, "rb");
  if (fp == 0) {
#endif
    printf("ParseReadFile:unable to open file:%s\n", filename);
    lx_free_parser(&yyp, &lxp);
    return 1;
  }

  char buf[1024];
  char* pbuf = buf;
  while(!feof(fp)) {
    size_t cnt = fread(pbuf, 1, (size_t)(1024 - (pbuf - buf) - 1), fp);
    char* buf_end = buf+(pbuf-buf)+cnt;
    *buf_end = 0;
    int is_final = 0;
    if((buf_end - buf) < 1023) {is_final = 1;}
#if ParseLX_INTEGRATEDMODE
    int rc = ParseRead(yyp, buf, buf_end, is_final ParseARG_VNAME);
#else
    int rc = ParseRead(yyp, lxp, buf, buf_end, is_final ParseARG_VNAME);
#endif
    if(rc < 0){
      printf("error in file:%d\n", rc);
      fclose(fp);
      lx_free_parser(&yyp, &lxp);
      return 1;
    }
    if(rc > 0){
      char* ebuf = buf_end - rc;
      for(int i = 0; i < rc; ++i) {
        buf[i] = ebuf[i];
      }
    }
    pbuf = buf+rc;
  }

  fclose(fp);
  lx_free_parser(&yyp, &lxp);
  return 0;
}
#endif /* LEMONEX */
