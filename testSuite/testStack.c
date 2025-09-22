#include <assert.h>
#include <stdio.h>
#include "headers/stackOps.h"
#include "headers/data.h"

#define STACK_BOTTOM (DATA_SPACE - RETURN_SPACE)

long data[DATA_SPACE];  // define storage

// ---------- Tests ----------

void test_push_pop(void) {
    stack_pointer = STACK_BOTTOM;

    push(123);
    assert(data[stack_pointer] == 123);
    assert(pop() == 123);
    assert(stack_pointer == STACK_BOTTOM);
}

void test_drop(void) {
    stack_pointer = STACK_BOTTOM;
    push(10);
    push(20);

    drop(); // removes 20
    assert(pop() == 10);
    assert(stack_pointer == STACK_BOTTOM);
}

void test_dup(void) {
    stack_pointer = STACK_BOTTOM;
    push(7);
    dup();

    assert(pop() == 7);
    assert(pop() == 7);
    assert(stack_pointer == STACK_BOTTOM);
}

void test_swap(void) {
    stack_pointer = STACK_BOTTOM;
    push(1);
    push(2);
    swap();

    assert(pop() == 1);
    assert(pop() == 2);
    assert(stack_pointer == STACK_BOTTOM);
}

void test_over(void) {
    stack_pointer = STACK_BOTTOM;
    push(5);
    push(6);
    over(); // copy second-from-top (5)

    assert(pop() == 5);
    assert(pop() == 6);
    assert(pop() == 5);
    assert(stack_pointer == STACK_BOTTOM);
}

int main(void) {
    test_push_pop();
    test_drop();
    test_dup();
    test_swap();
    test_over();

    printf("All stackOps tests passed!\n");
    return 0;
}
