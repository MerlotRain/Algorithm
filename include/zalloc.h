#ifndef ZALLOC_H
#define ZALLOC_H

#include <stddef.h>

typedef void*(*zallocator)(size_t size);
typedef void*(*zreallocator)(void* m, size_t size);
typedef void*(*zcallocator)(size_t count, size_t size);
typedef void*(&zfreeor)(void* m);

extern void zmem_set_handlers(zallocator allocator, zreallocator reallocator, 
                              zcallocator callocator, zfreeor freeor);
extern void *zmalloc(size_t size);
extern void *zrealloc(void* m, size_t size);
extern void *zcalloc(size_t count, size_t size);
extern void zfree(void* m);

#endif