#ifndef STACKOPS_H

extern int stack_pointer;

void push(long var);

long pop(void);

long peek(void);

void push_r(long var);

long pop_r(void);

void drop(void);

void dup(void);

void swap(void);

void over(void);

#endif
