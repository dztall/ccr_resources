#ifndef TGC_H
#define TGC_H


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  void *ptr;
  int flags, line;
  size_t size, hash;
  void (*dtor)(void*);
  char * file;
  char * func;
} tgc_ptr_t;

typedef struct {
	void (*callback_entry)(void*);
	void (*callback_exit)(void*);
	void (*callback_source)(char*,int,char*);
	void (*callback_error)(char*,char*);
	void (*callback_forgot_to_init)(char*);
	void (*callback_unfreed_info)(FILE*,tgc_ptr_t);
	void (*callback_unfreed_total)(FILE*,size_t);
	void (*callback_add)(void*,size_t);
	void (*callback_remove)(void*);
	void (*callback_realloc)(void*, size_t);
	void (*callback_free)(void*);
	void (*callback_startup)(int);
	void (*callback_shutdown)(int);
	void (*callback_pause)(int);
} tgc_callbacks;

typedef struct {
  tgc_callbacks callbacks;
  int init;
  void *bottom;
  int paused;
  uintptr_t minptr, maxptr;
  tgc_ptr_t *items, *frees;
  double loadfactor, sweepfactor;
  size_t nitems, nslots, mitems, nfrees;
} tgc_t = {0};

void tgc_start(tgc_t *gc, void *stk);
void tgc_stop(tgc_t *gc, char * src_file, int src_line, char * src_func);
void tgc_resume(tgc_t *gc);
void tgc_pause(tgc_t *gc);
void tgc_run(tgc_t *gc, char * src_file, int src_line, char * src_func);
void tgc_dump(tgc_t *gc, FILE * fp);

void tgc_dump(tgc_t *gc, FILE * fp);
void *tgc_alloc(tgc_t *gc, size_t size, char * src_file, int src_line, char * src_func);
void *tgc_calloc(tgc_t *gc, size_t num, size_t size, char * src_file, int src_line, char * src_func);
void *tgc_realloc(tgc_t *gc, void *ptr, size_t size, char * src_file, int src_line, char * src_func);
void tgc_free(tgc_t *gc, void *ptr, char * src_file, int src_line, char * src_func);

void *tgc_alloc_opt(tgc_t *gc, size_t size, int flags, void(*dtor)(void*), char * src_file, int src_line, char * src_func);
void *tgc_calloc_opt(tgc_t *gc, size_t num, size_t size, int flags, void(*dtor)(void*), char * src_file, int src_line, char * src_func);

void tgc_set_dtor(tgc_t *gc, void *ptr, void(*dtor)(void*), char * src_file, int src_line, char * src_func);
void tgc_set_flags(tgc_t *gc, void *ptr, int flags, char * src_file, int src_line, char * src_func);
int tgc_get_flags(tgc_t *gc, void *ptr, char * src_file, int src_line, char * src_func);
void(*tgc_get_dtor(tgc_t *gc, void *ptr, char * src_file, int src_line, char * src_func))(void*);
size_t tgc_get_size(tgc_t *gc, void *ptr, char * src_file, int src_line, char * src_func);

tgc_t Garbage_Collector_Program;

#define Garbage_Collector_Start() tgc_start(&Garbage_Collector_Program)
#define Garbage_Collector_Shutdown() tgc_stop(&Garbage_Collector_Program, __FILE__, __LINE__, __FUNCTION__)
#define Garbage_Collector_Cleanup() tgc_sweep(&Garbage_Collector_Program, __FILE__, __LINE__, __FUNCTION__)
#define Garbage_Collector_Resume() tgc_resume(&Garbage_Collector_Program, __FILE__, __LINE__, __FUNCTION__)
#define Garbage_Collector_Pause() tgc_pause(&Garbage_Collector_Program)
static void Garbage_Collector_Dump_Mem(FILE *fp) { return tgc_dump(&Garbage_Collector_Program, fp); }

void * Garbage_Collector_atexit(void) {
	if (Garbage_Collector_Program.init == 1) {
		puts("Garbage Collector: ATEXIT: cleaning up");
		Garbage_Collector_Dump_Mem(stdout);
		Garbage_Collector_Shutdown();
		puts("Garbage Collector: ATEXIT: clean up successfull");
	}
	return (void*)0;
}

int Garbage_Collector_Initilizer_atexit = atexit(Garbage_Collector_atexit);

#define Garbage_Collector_Debug_None (1)
#define Garbage_Collector_Debug_Normal (1<<1)
#define Garbage_Collector_Debug_List (1<<2)
#define Garbage_Collector_Debug_Free (1<<3)
#define Garbage_Collector_Debug_Realloc (1<<4)
int Garbage_Collector_Debug;
#define GCDEBUG if (Garbage_Collector_Debug & Garbage_Collector_Debug_Normal)
#define GCDEBUG_LIST if (Garbage_Collector_Debug & Garbage_Collector_Debug_Normal || Garbage_Collector_Debug & Garbage_Collector_Debug_List)
#define GCDEBUG_FREE if (Garbage_Collector_Debug & Garbage_Collector_Debug_Normal || Garbage_Collector_Debug & Garbage_Collector_Debug_Free)
#define GCDEBUG_REALLOC if (Garbage_Collector_Debug & Garbage_Collector_Debug_Normal || Garbage_Collector_Debug & Garbage_Collector_Debug_Realloc)

#define Garbage_Collector_Options_None (1)
#define Garbage_Collector_Options_No_Recycle (1<<1)
#define Garbage_Collector_Options_Recycle (1<<2)
#define Garbage_Collector_Options_Quiet (1<<3)
#define Garbage_Collector_Options_Default Garbage_Collector_Options_No_Recycle
int Garbage_Collector_Options = Garbage_Collector_Options_Default;

#include <stdio.h>


#include <string.h>
#include <setjmp.h>
#include <assert.h>
#include <fcntl.h>

enum {
  TGC_MARK = 0x01,
  TGC_ROOT = 0x02,
  TGC_LEAF = 0x04
};

#include "signal_handler.h"


int get_file(char *file, int line)
{
    FILE *file1;
    char * line1 = malloc(4096);
    int line_count1=1;
    size_t m=0;
    
    if (access(file, F_OK)) {
    	perror(file);
    	return -1;
    }
    file1 = fopen(file,"r");
    while (1) {
    	if(fgets(line1, 4096, file1)!=0) if (line_count1 >= line) break;
    	line_count1++;
    }
    printf("%s: %d: \n%s\n", file, line_count1, line1);
    free(line1);
    fclose(file1);
    return 0;
}


#define Garbage_Collector_Pointer_Add_First_Pointer -1
#define Garbage_Collector_Pointer_Add_Already_Exists -2
#define Garbage_Collector_Pointer_Add_New_Pointer -3


#define Garbage_Collector_Events_Startup_Begin 1
#define Garbage_Collector_Events_Startup_End 0
#define Garbage_Collector_Events_Shutdown_Begin 3
#define Garbage_Collector_Events_Shutdown_End 2
#define Garbage_Collector_Events_Pause 5
#define Garbage_Collector_Events_Resume 4


void tgc_callbacks_default_startup(int status) {
	if (Garbage_Collector_Options & Garbage_Collector_Options_Quiet) {}
	else {
		if (status == Garbage_Collector_Events_Startup_Begin) puts("Garbage Collector: Starting ");
		else if (status == Garbage_Collector_Events_Startup_End) puts("Garbage Collector: Successfully started");
	}
	return;
}

void tgc_callbacks_default_shutdown(int status) {
	if (Garbage_Collector_Options & Garbage_Collector_Options_Quiet) {}
	else {
		if (status == Garbage_Collector_Events_Shutdown_Begin) puts("Garbage Collector: Shuting down ");
		else if (status == Garbage_Collector_Events_Shutdown_End) puts("Garbage Collector: Successfully shutdown");
	}
	return;
}

void tgc_callbacks_default_pause(int status) {
	if (Garbage_Collector_Options & Garbage_Collector_Options_Quiet) {}
	else {
		if (status == Garbage_Collector_Events_Pause) puts("Garbage Collector: Paused ");
		else if (status == Garbage_Collector_Events_Resume) puts("Garbage Collector: Resumed");
	}
	return;
}

void tgc_callbacks_default_entry(char * function) {
	if (Garbage_Collector_Options & Garbage_Collector_Options_Quiet) {}
	else {
		GCDEBUG printf("Garbage Collector: Entering function: %s\n", function);
	}
	return;
}

void tgc_callbacks_default_add(void * pointer, int status) {
	if (Garbage_Collector_Options & Garbage_Collector_Options_Quiet) {}
		else {
		if (status == Garbage_Collector_Pointer_Add_First_Pointer || status == Garbage_Collector_Pointer_Add_New_Pointer) GCDEBUG_LIST printf("Garbage Collector: adding %p to the list\n", pointer);
		else if (status == Garbage_Collector_Pointer_Add_Already_Exists) GCDEBUG_LIST printf("Garbage Collector: %p has already been added the list\n", pointer);
	}
	return;
}

void tgc_callbacks_default_remove(void * pointer) {
	if (Garbage_Collector_Options & Garbage_Collector_Options_Quiet) {}
	else {
		GCDEBUG_LIST printf("Garbage Collector: removing %p from the list\n", pointer);
	}
	return;
}

void tgc_callbacks_default_realloc(void * pointer, size_t old, size_t new) {
	if (Garbage_Collector_Options & Garbage_Collector_Options_Quiet) {}
	else {
		GCDEBUG_REALLOC printf("Garbage Collector: reallocating %p from %zu to %zu\n", pointer, old, new);
	}
	return;
}

void tgc_callbacks_default_free(void * pointer) {
	if (Garbage_Collector_Options & Garbage_Collector_Options_Quiet) {}
	else {
		GCDEBUG_FREE printf("Garbage Collector: freeing %p\n", pointer);
	}
	return;
}

void tgc_callbacks_default_exit(void * function) {
	if (Garbage_Collector_Options & Garbage_Collector_Options_Quiet) {}
	else {
		GCDEBUG printf("Garbage Collector: Exiting function: %s\n", function);
	}
	return;
}

void tgc_callbacks_default_source(char * src_file, int src_line, char * src_func) {
	if (Garbage_Collector_Options & Garbage_Collector_Options_Quiet) {}
	else {
		GCDEBUG printf("Garbage Collector: file: %s\nGarbage Collector: line: %d\nGarbage Collector: function: %s\n", src_file, src_line, src_func);
	}
	return;
}

void tgc_callbacks_default_error(char * func, char * reason) {
	printf("Garbage Collector: error: %s: %s\n", func, reason);
	return;
}

void tgc_callbacks_default_forgot_to_init(char * func) {
	printf("Garbage Collector: Error: You have attempted to %s something without initializing me first\nGarbage Collector: Please initialize me by using [ Garbage_Collector_Init_Minimal_Stack(); ]\nGarbage Collector: Cannot continue\n", func);
	exit();
	return;
}

void tgc_callbacks_default_unfreed_info(FILE * fp, tgc_ptr_t item) {
	if (Garbage_Collector_Options & Garbage_Collector_Options_Quiet) {}
	else {
		fprintf(fp, "Garbage Collector: Unfreed: %p, first allocated in file %s, line %zu, from function %s, with current total usage of %zu bytes\nsource line:\n", item.ptr, item.file, item.line, item.func, item.size);
		get_file(item.file, item.line);
		puts("");
	}
	return;
}
void tgc_callbacks_default_unfreed_total(FILE * fp, size_t total ) {
	if (Garbage_Collector_Options & Garbage_Collector_Options_Quiet) {}
	else {
		fprintf(fp, "Garbage Collector: Total unfreed: %zu bytes\n", total);
	}
	return;
}

tgc_callbacks tgc_callbacks_default = {
	tgc_callbacks_default_entry,
	tgc_callbacks_default_exit,
	tgc_callbacks_default_source,
	tgc_callbacks_default_error,
	tgc_callbacks_default_forgot_to_init,
	tgc_callbacks_default_unfreed_info,
	tgc_callbacks_default_unfreed_total,
	tgc_callbacks_default_add,
	tgc_callbacks_default_remove,
	tgc_callbacks_default_realloc,
	tgc_callbacks_default_free,
	tgc_callbacks_default_startup,
	tgc_callbacks_default_shutdown,
	tgc_callbacks_default_pause
};


Garbage_Collector_Program.callbacks = tgc_callbacks_default;

int Garbage_Collector_Initilizer_Start = Garbage_Collector_Start();

static size_t tgc_hash(tgc_t* gc, void *ptr) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  return ((uintptr_t)ptr) >> 3;
}

static size_t tgc_probe(tgc_t* gc, size_t i, size_t h) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  long v = i - (h-1);
  if (v < 0) { v = gc->nslots + v; }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  return v;
}

static tgc_ptr_t *tgc_get_ptr(tgc_t *gc, void *ptr, char * src_file, int src_line, char * src_func,  char * name) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  size_t i, j, h;
  i = tgc_hash(gc, ptr) % gc->nslots; j = 0;
  while (1) {
    h = gc->items[i].hash;
    if (h == 0 || j > tgc_probe(gc, i, h)) { 
    	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
    	return NULL;
    }
    if (gc->items[i].ptr == ptr) { 
    	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
    	return &gc->items[i];
    }
    i = (i+1) % gc->nslots; j++;
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  return NULL;
}

static void tgc_add_ptr(
  tgc_t *gc, void *ptr, size_t size, 
  int flags, void(*dtor)(void*), char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);

  tgc_ptr_t item, tmp;
  size_t h, p, i, j;

  i = tgc_hash(gc, ptr) % gc->nslots; j = 0;
  
  item.ptr = ptr;
  item.flags = flags;
  item.size = size;
  item.hash = i+1;
  item.dtor = dtor;
  item.file = src_file;
  item.line = src_line;
  item.func = src_func;
  
  while (1) {
    h = gc->items[i].hash;
    if (h == 0) {
    	gc->items[i] = item;
  		if (gc->callbacks.callback_add) gc->callbacks.callback_add(ptr, Garbage_Collector_Pointer_Add_First_Pointer);
    	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
    	return;
    }
    if (gc->items[i].ptr == item.ptr) {
  		if (gc->callbacks.callback_add) gc->callbacks.callback_add(ptr, Garbage_Collector_Pointer_Add_Already_Exists);
    	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
    	return;
    }
    p = tgc_probe(gc, i, h);
    if (j >= p) {
  		if (gc->callbacks.callback_add) gc->callbacks.callback_add(ptr, Garbage_Collector_Pointer_Add_New_Pointer);
      tmp = gc->items[i];
      gc->items[i] = item;
      item = tmp;
      j = p;
    }
    i = (i+1) % gc->nslots; j++;
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

static void tgc_rem_ptr(tgc_t *gc, void *ptr) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);

  size_t i, j, h, nj, nh;

  if (gc->nitems == 0) {
  	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  	return;
  }
  
  for (i = 0; i < gc->nfrees; i++) {
    if (gc->frees[i].ptr == ptr) { 
    	if (gc->callbacks.callback_remove) gc->callbacks.callback_remove(gc->frees[i].ptr);
    	gc->frees[i].ptr = NULL;
    }
  }
  
  i = tgc_hash(gc, ptr) % gc->nslots; j = 0;
  
  while (1) {
    h = gc->items[i].hash;
    if (h == 0 || j > tgc_probe(gc, i, h)) { 
    	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
    	return;
    }
    if (gc->items[i].ptr == ptr) {
      if (gc->callbacks.callback_remove) gc->callbacks.callback_remove(gc->items[i].ptr);
      memset(&gc->items[i], 0, sizeof(tgc_ptr_t));
      j = i;
      while (1) { 
        nj = (j+1) % gc->nslots;
        nh = gc->items[nj].hash;
        if (nh != 0 && tgc_probe(gc, nj, nh) > 0) {
          memcpy(&gc->items[ j], &gc->items[nj], sizeof(tgc_ptr_t));
          memset(&gc->items[nj],              0, sizeof(tgc_ptr_t));
          j = nj;
        } else {
          break;
        }  
      }
      gc->nitems--;
      if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
      return;
    }
    i = (i+1) % gc->nslots; j++;
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}


enum {
  TGC_PRIMES_COUNT = 24
};

static const size_t tgc_primes[TGC_PRIMES_COUNT] = {
  0,       1,       5,       11,
  23,      53,      101,     197,
  389,     683,     1259,    2417,
  4733,    9371,    18617,   37097,
  74093,   148073,  296099,  592019,
  1100009, 2200013, 4400021, 8800019
};

static size_t tgc_ideal_size(tgc_t* gc, size_t size) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  size_t i, last;
  size = (size_t)((double)(size+1) / gc->loadfactor);
  for (i = 0; i < TGC_PRIMES_COUNT; i++) {
    if (tgc_primes[i] >= size) { 
    	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
    	return tgc_primes[i];
    }
  }
  last = tgc_primes[TGC_PRIMES_COUNT-1];
  for (i = 0;; i++) {
    if ((last * i) >= size) {
    	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
    	return last * i;
    }
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  return 0;
}

static int tgc_rehash(tgc_t* gc, size_t new_size, char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);

  size_t i;
  tgc_ptr_t *old_items = gc->items;
  size_t old_size = gc->nslots;
  
  gc->nslots = new_size;
  gc->items = calloc(gc->nslots, sizeof(tgc_ptr_t));
  
  if (gc->items == NULL) {
    gc->nslots = old_size;
    gc->items = old_items;
    if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
    return 0;
  }
  
  for (i = 0; i < old_size; i++) {
    if (old_items[i].hash != 0) {
      tgc_add_ptr(gc, 
        old_items[i].ptr,   old_items[i].size, 
        old_items[i].flags, old_items[i].dtor,
      	src_file, src_line, src_func);
    }
  }
  
  free(old_items);
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  return 1;
}

static int tgc_resize_more(tgc_t *gc, char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  size_t new_size = tgc_ideal_size(gc, gc->nitems);
  size_t old_size = gc->nslots;
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  return (new_size > old_size) ? tgc_rehash(gc, new_size, src_file, src_line, src_func) : 1;
}

static int tgc_resize_less(tgc_t *gc, char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  size_t new_size = tgc_ideal_size(gc, gc->nitems);  
  size_t old_size = gc->nslots;
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  return (new_size < old_size) ? tgc_rehash(gc, new_size, src_file, src_line, src_func) : 1;
}

static void tgc_mark_ptr(tgc_t *gc, void *ptr) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);

  size_t i, j, h, k;
  
  if ((uintptr_t)ptr < gc->minptr 
  ||  (uintptr_t)ptr > gc->maxptr) { 
  	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  	return;
  }
  
  i = tgc_hash(gc, ptr) % gc->nslots; j = 0;
  
  while (1) {
    h = gc->items[i].hash;
    if (h == 0 || j > tgc_probe(gc, i, h)) { 
    	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
    	return;
    }
    if (ptr == gc->items[i].ptr) {
      if (gc->items[i].flags & TGC_MARK) {
      	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
      	return;
      }
      gc->items[i].flags |= TGC_MARK;
      if (gc->items[i].flags & TGC_LEAF) {
      	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
      	return;
      }
      for (k = 0; k < gc->items[i].size/sizeof(void*); k++) {
        tgc_mark_ptr(gc, ((void**)gc->items[i].ptr)[k]);
      }
      if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
      return;
    }
    i = (i+1) % gc->nslots; j++;
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

static void tgc_mark_stack(tgc_t *gc) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  
  void *stk, *bot, *top, *p;
  bot = gc->bottom; top = &stk;
  
  if (bot == top) {
  	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  	return;
  }
  
  if (bot < top) {
    for (p = top; p >= bot; p = ((char*)p) - sizeof(void*)) {
      tgc_mark_ptr(gc, *((void**)p));
    }
  }
  
  if (bot > top) {
    for (p = top; p <= bot; p = ((char*)p) + sizeof(void*)) {
      tgc_mark_ptr(gc, *((void**)p));
    }
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

static void tgc_mark(tgc_t *gc) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  
  size_t i, k;
  jmp_buf env;
  void (*volatile mark_stack)(tgc_t*) = tgc_mark_stack;
  
  if (gc->nitems == 0) { 
  	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  	return;
  }
  
  for (i = 0; i < gc->nslots; i++) {
    if (gc->items[i].hash ==        0) { continue; }
    if (gc->items[i].flags & TGC_MARK) { continue; }
    if (gc->items[i].flags & TGC_ROOT) {
      gc->items[i].flags |= TGC_MARK;
      if (gc->items[i].flags & TGC_LEAF) { continue; }
      for (k = 0; k < gc->items[i].size/sizeof(void*); k++) {
        tgc_mark_ptr(gc, ((void**)gc->items[i].ptr)[k]);
      }
      continue;
    }
  }
  
  memset(&env, 0, sizeof(jmp_buf));
  setjmp(env);
  mark_stack(gc);
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

void tgc_sweep(tgc_t *gc, char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  
  size_t i, j, k, nj, nh;
  
  if (gc->nitems == 0) {
  	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  	return;
  }
  
  gc->nfrees = 0;
  for (i = 0; i < gc->nslots; i++) {
    if (gc->items[i].hash ==        0) { continue; }
    if (gc->items[i].flags & TGC_MARK) { continue; }
    if (gc->items[i].flags & TGC_ROOT) { continue; }
    gc->nfrees++;
  }

  gc->frees = realloc(gc->frees, sizeof(tgc_ptr_t) * gc->nfrees);
  if (gc->frees == NULL) {
  	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  	return;
  }
  
  i = 0; k = 0;
  while (i < gc->nslots) {
    if (gc->items[i].hash ==        0) { i++; continue; }
    if (gc->items[i].flags & TGC_MARK) { i++; continue; }
    if (gc->items[i].flags & TGC_ROOT) { i++; continue; }
    
    gc->frees[k] = gc->items[i]; k++;
    memset(&gc->items[i], 0, sizeof(tgc_ptr_t));
    
    j = i;
    while (1) { 
      nj = (j+1) % gc->nslots;
      nh = gc->items[nj].hash;
      if (nh != 0 && tgc_probe(gc, nj, nh) > 0) {
        memcpy(&gc->items[ j], &gc->items[nj], sizeof(tgc_ptr_t));
        memset(&gc->items[nj],              0, sizeof(tgc_ptr_t));
        j = nj;
      } else {
        break;
      }  
    }
    gc->nitems--;
  }
  
  for (i = 0; i < gc->nslots; i++) {
    if (gc->items[i].hash == 0) { continue; }
    if (gc->items[i].flags & TGC_MARK) {
      gc->items[i].flags &= ~TGC_MARK;
    }
  }
  
  tgc_resize_less(gc, src_file, src_line, src_func);
  
  gc->mitems = gc->nitems + (size_t)(gc->nitems * gc->sweepfactor) + 1;
  
  for (i = 0; i < gc->nfrees; i++) {
    if (gc->frees[i].ptr) {
      if (gc->frees[i].dtor) { gc->frees[i].dtor(gc->frees[i].ptr); }
      if (gc->callbacks.callback_free) gc->callbacks.callback_free(gc->frees[i].ptr);
      free(gc->frees[i].ptr);
    }
  }
  
  free(gc->frees);
  gc->frees = NULL;
  gc->nfrees = 0;
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

#include "gc/stack.h"
void tgc_start(tgc_t *gc) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_startup) gc->callbacks.callback_startup(Garbage_Collector_Events_Startup_Begin);
  int a = 0;
  gc->init = 1;
  #ifdef Garbage_Collector_Full_Scan
	#ifndef __APPLE__
	  #warning unsupported OS, this currently only supports Apple ios/macosx, full stack scanning will be disabled
      gc->bottom = &a;
	#else
      gc->bottom = find_stack(&a);
	#endif
  #else
    gc->bottom = &a;
  #endif
  gc->paused = 0;
  gc->nitems = 0;
  gc->nslots = 0;
  gc->mitems = 0;
  gc->nfrees = 0;
  gc->maxptr = 0;
  gc->items = NULL;
  gc->frees = NULL;
  gc->minptr = UINTPTR_MAX;
  gc->loadfactor = 0.9;
  gc->sweepfactor = 0.5;
  if (gc->callbacks.callback_startup) gc->callbacks.callback_startup(Garbage_Collector_Events_Startup_End);
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

void tgc_stop(tgc_t *gc, char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_shutdown) gc->callbacks.callback_shutdown(Garbage_Collector_Events_Shutdown_Begin);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  tgc_sweep(gc, src_file, src_line, src_func);
  free(gc->items);
  free(gc->frees);
  gc->init = 0;
  if (gc->callbacks.callback_shutdown) gc->callbacks.callback_shutdown(Garbage_Collector_Events_Shutdown_End);
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

void tgc_pause(tgc_t *gc) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  gc->paused = 1;
  if (gc->callbacks.callback_pause) gc->callbacks.callback_pause(Garbage_Collector_Events_Pause);
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

void tgc_resume(tgc_t *gc) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  gc->paused = 0;
  if (gc->callbacks.callback_pause) gc->callbacks.callback_pause(Garbage_Collector_Events_Resume);
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

void tgc_run(tgc_t *gc, char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  tgc_mark(gc);
  tgc_sweep(gc, src_file, src_line, src_func);
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

static void *tgc_add(
  tgc_t *gc, void *ptr, size_t size, 
  int flags, void(*dtor)(void*), char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);

  gc->nitems++;
  gc->maxptr = ((uintptr_t)ptr) + size > gc->maxptr ? 
    ((uintptr_t)ptr) + size : gc->maxptr; 
  gc->minptr = ((uintptr_t)ptr)        < gc->minptr ? 
    ((uintptr_t)ptr)        : gc->minptr;

  if (tgc_resize_more(gc, src_file, src_line, src_func)) {
    tgc_add_ptr(gc, ptr, size, flags, dtor, src_file, src_line, src_func);
    if (!(Garbage_Collector_Options & Garbage_Collector_Options_No_Recycle)) if (!gc->paused && gc->nitems > gc->mitems) {
      tgc_run(gc, src_file, src_line, src_func);
    }
    if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
    return ptr;
  } else {
    gc->nitems--;
    if (gc->callbacks.callback_free) gc->callbacks.callback_free(ptr);
    free(ptr);
    if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
    return NULL;
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

static void tgc_rem(tgc_t *gc, void *ptr, char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  tgc_rem_ptr(gc, ptr);
  tgc_resize_less(gc, src_file, src_line, src_func);
  gc->mitems = gc->nitems + gc->nitems / 2 + 1;
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

void *tgc_alloc(tgc_t *gc, size_t size, char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  if (gc->init == 0) {
  	if (gc->callbacks.callback_forgot_to_init) gc->callbacks.callback_forgot_to_init("malloc");
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  return tgc_alloc_opt(gc, size, 0, NULL, src_file, src_line, src_func);
}

void *tgc_calloc(tgc_t *gc, size_t num, size_t size, char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  if (gc->init == 0) {
  	if (gc->callbacks.callback_forgot_to_init) gc->callbacks.callback_forgot_to_init("calloc");
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  return tgc_calloc_opt(gc, num, size, 0, NULL, src_file, src_line, src_func);
}

void *tgc_realloc(tgc_t *gc, void *ptr, size_t size, char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  if (gc->init == 0) {
  	if (gc->callbacks.callback_forgot_to_init) gc->callbacks.callback_forgot_to_init("realloc");
  }
  tgc_ptr_t *p;
  void *qtr = realloc(ptr, size);
  
  if (qtr == NULL) {
    tgc_rem(gc, ptr, src_file, src_line, src_func);
    if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
    return qtr;
  }

  if (ptr == NULL) {
    tgc_add(gc, qtr, size, 0, NULL, src_file, src_line, src_func);
    if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
    return qtr;
  }

  p  = tgc_get_ptr(gc, ptr, src_file, src_line, src_func, "realloc");

  if (p && qtr == ptr) {
  	if (gc->callbacks.callback_realloc) gc->callbacks.callback_realloc(ptr, p->size, size);
    p->size = size;
    if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
    return qtr;
  }

  if (p && qtr != ptr) {
    int flags = p->flags;
    void(*dtor)(void*) = p->dtor;
    if (gc->callbacks.callback_realloc) gc->callbacks.callback_realloc(ptr, p->size, size);
    tgc_rem(gc, ptr, src_file, src_line, src_func);
    tgc_add(gc, qtr, size, flags, dtor, src_file, src_line, src_func);
    if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
    return qtr;
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  return NULL;
}

void tgc_free(tgc_t *gc, void *ptr, char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  if (gc->init == 0) {
  	if (gc->callbacks.callback_forgot_to_init) gc->callbacks.callback_forgot_to_init("free");
  }
  tgc_ptr_t *p  = tgc_get_ptr(gc, ptr, src_file, src_line, src_func, "free");
  if (p) {
    if (p->dtor) {
      p->dtor(ptr);
    }
    if (gc->callbacks.callback_free) gc->callbacks.callback_free(ptr);
    free(ptr);
    tgc_rem(gc, ptr, src_file, src_line, src_func);
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

void *tgc_alloc_opt(tgc_t *gc, size_t size, int flags, void(*dtor)(void*), char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  void *ptr = malloc(size);
  if (ptr != NULL) {
    ptr = tgc_add(gc, ptr, size, flags, dtor, src_file, src_line, src_func);
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  return ptr;
}

void *tgc_calloc_opt(
  tgc_t *gc, size_t num, size_t size, 
  int flags, void(*dtor)(void*), char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  void *ptr = calloc(num, size);
  if (ptr != NULL) {
    ptr = tgc_add(gc, ptr, num * size, flags, dtor, src_file, src_line, src_func);
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  return ptr;
}

void tgc_set_dtor(tgc_t *gc, void *ptr, void(*dtor)(void*), char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  tgc_ptr_t *p  = tgc_get_ptr(gc, ptr, src_file, src_line, src_func, "pointer");
  if (p) { p->dtor = dtor; }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

void tgc_set_flags(tgc_t *gc, void *ptr, int flags, char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  tgc_ptr_t *p  = tgc_get_ptr(gc, ptr, src_file, src_line, src_func, "pointer");
  if (p) { p->flags = flags; }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

int tgc_get_flags(tgc_t *gc, void *ptr, char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  tgc_ptr_t *p  = tgc_get_ptr(gc, ptr, src_file, src_line, src_func, "pointer");
  if (p) {
  	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  	return p->flags;
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  return 0;
}

void(*tgc_get_dtor(tgc_t *gc, void *ptr, char * src_file, int src_line, char * src_func))(void*) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  tgc_ptr_t *p  = tgc_get_ptr(gc, ptr, src_file, src_line, src_func, "pointer");
  if (p) { 
  	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  	return p->dtor; 
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  return NULL;
}

size_t tgc_get_size(tgc_t *gc, void *ptr, char * src_file, int src_line, char * src_func) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  if (gc->callbacks.callback_source) gc->callbacks.callback_source(src_file, src_line, src_func);
  tgc_ptr_t *p  = tgc_get_ptr(gc, ptr, src_file, src_line, src_func, "size");
  if (p) { 
  	if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  	return p->size; 
  }
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
  return 0;
}

void tgc_dump(tgc_t *gc, FILE * fp) {
  if (gc->callbacks.callback_entry) gc->callbacks.callback_entry(__FUNCTION__);
  size_t total = 0;

  if (!fp) fp = stdout;

  for (int i = 0; i < gc->nslots; i++) {
    if (gc->items[i].hash == 0 || gc->items[i].line == NULL) { continue; }
    if (gc->callbacks.callback_unfreed_info) gc->callbacks.callback_unfreed_info(fp, gc->items[i]);
    total += gc->items[i].size;
  }

  if (gc->callbacks.callback_unfreed_total) gc->callbacks.callback_unfreed_total(fp, total);
  if (gc->callbacks.callback_exit) gc->callbacks.callback_exit(__FUNCTION__);
}

#define malloc(size)  tgc_alloc(&Garbage_Collector_Program, size, __FILE__, __LINE__, __FUNCTION__)
#define calloc(num, size)  tgc_calloc(&Garbage_Collector_Program, num, size, __FILE__, __LINE__, __FUNCTION__)
#define realloc(ptr, size) tgc_realloc(&Garbage_Collector_Program, ptr, size, __FILE__, __LINE__, __FUNCTION__)
#define free(ptr)    tgc_free(&Garbage_Collector_Program, ptr, __FILE__, __LINE__, __FUNCTION__)

#endif
