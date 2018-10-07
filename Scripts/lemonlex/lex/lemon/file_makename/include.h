// line 6072
// inside PRIVATE char *file_makename(struct lemon *lemp, const char *suffix)
#ifdef LEMONEX
  cp = strrchr(lemp->filename,'/');
  if(!ofiledir) cp++;
  if(*cp == '.') cp++;
  if(*cp == '/') cp++;
  if(cp == 0)
      cp = strrchr(lemp->filename,'\\');
  if(cp == 0)
      cp = lemp->filename;
  size_t len = lemonStrlen(ofiledir) + lemonStrlen(cp) + lemonStrlen(suffix) + 5 +1+1;
  name = malloc(len);
  memset(name,0,len);
  if( name==0 ){
    fprintf(stderr,"Can't allocate space for a filename.\n");
    exit(1);
  }
  strcpy(name,ofiledir);
  if (*cp != '/' || (lemp->filename[0] != '.' && lemp->filename[1] != '/')) strcat(name,"/");
  strcat(name,cp);
#else
  name = (char*)malloc( lemonStrlen(lemp->filename) + lemonStrlen(suffix) + 5 +1);
  if( name==0 ){
    fprintf(stderr,"Can't allocate space for a filename.\n");
    exit(1);
  }
  lemon_strcpy(name,lemp->filename);
#endif
