#include "stack.h"
#include "zalloc.h"

struct stack_node {
    void * data;
    struct stack_node * prev;
};

typedef struct stack {
    deletor _del;
    struct stack_node *top;
} stack_t;


stack_t* stack_new(deletor del)
{
    stack_t * s = (stack_t *)zmalloc(sizeof(stack_t));
    if(s == NULL)
        return NULL;

    s->_del = del;
    s->top = NULL;
    return s;
}

void stack_free(stack_t *t) 
{
    assert(t);
    do
    {
        struct stack_node *prev = t->top;
        if(t->_del)
        {  
            (t->_del)(t->data);            
        }
        else
        {
            zfree(t->data);
        }
    } while(prev);
    zfree(t);
}

void *stack_top(stack_t *t)
{
    return NULL;
}

void stack_push(stack_t *t, void* d)
{
}

void *stack_pop(stack_t *t)
{
    return NULL;
}

size_t stack_size(const stack_t *t)
{
    return 0;
}