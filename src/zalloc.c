#include <stdlib.h>
#include <stddef.h>

static void * default_allocator(size_t size);
static void * default_reallocator(void *mem, size_t size);
static void * default_callocator(size_t count, size_t size);
static void default_freeor(void *mem);

zallocator zalloc_var = default_allocator;
zreallocator zrealloc_var = default_reallocator;
zcallocator zcalloc_var = default_callocator;
zfreeor zfree_var = default_freeor;

void zmem_set_handlers(zallocator allocator, zreallocator reallocator, 
                              zcallocator callocator, zfreeor freeor)
{
    if (allocator) zalloc_var = allocator;
    if (reallocator) zrealloc_var = reallocator;
    if (callocator) zcalloc_var = callocator;
    if (freeor) zfree_var = freeor;
}

void *zmalloc(size_t size)
{
    void *m = default_allocator(size);
    return m;
}

void *zrealloc(void* m, size_t size)
{
    void *m = default_reallocator(m, size);
    return m;
}

void *zcalloc(size_t count, size_t size)
{
    void* m = default_callocator(count, size);
    return m;
}

void zfree(void* m)
{
    default_freeor(m);
}

void * default_allocator(size_t size)
{
    void* m = malloc(size);
    return m;
}

void * default_reallocator(void *mem, size_t size)
{
    void * m = realloc(mem, size);
    return m;
}

void * default_callocator(size_t count, size_t size)
{
    void *m = calloc(count, size);
    return m;
}

void default_freeor(void *mem)
{
    free(mem);
}