// line 665
// inside void *ParseAlloc(void *(*mallocProc)(size_t)){
// inside   if( pParser ){
#if LEMONEX
#if ParseLX_INTEGRATEDMODE
    pParser->lxpLexer = (struct lxLexer*)ParseLexerAlloc(mallocProc);
#endif
#endif /* LEMONEX */
