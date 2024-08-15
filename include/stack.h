#ifndef STACK_H
#define STACK_H

typedef struct stack stack_t;

typedef void(*deletor)(void*);

stack_t* stack_new(deletor del);

void stack_free(stack_t *t);

void *stack_top(stack_t *t);

void stack_push(stack_t *t, void* d);

void *stack_pop(stack_t *t);

size_t stack_size(const stack_t *t);

#endif