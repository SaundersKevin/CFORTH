#ifndef DICTIONARYOPS_H

#define WORDLIST_SIZE 64

// 4 spots for 32 char, then 1 for execution token(pointer)
//extern long wordlist[WORDLIST_SIZE];

// I have so many pointers
// I really should try to find a way to consolidate, cause I don't
// Have this many registers to use
// I think I am at 4 right now
// I will use this to point to the beginning of the information
// of the previous word. 
extern long * wordlist_pointer;

void create(void);

void allot(void);

void variable(void);

void constant(void);

#endif
