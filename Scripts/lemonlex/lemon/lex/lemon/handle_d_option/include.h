#if defined(_WIN32)
    int rv = _mkdir(z);
#else
    int rv = mkdir(z, S_IRWXU | S_IRGRP | S_IROTH);
#endif
    if((rv == -1) && (errno != EEXIST)) {
      printf("Error creating directory(%d):%s\n", rv, z);
      exit(1);
    }
