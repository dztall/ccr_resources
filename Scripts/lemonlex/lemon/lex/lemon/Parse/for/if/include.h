// line 5913
// inside void Parse(struct lemon *gp)
// inside   for(cp=filebuf; (c= *cp)!=0; ){
// inside     if( c=='\"' ){                     /* String literals */
#ifdef LEMONEX
        if((c == '\\') && (cp[1] != 0)){
            cp++;
        }
#endif
