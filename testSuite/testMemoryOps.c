#include <stdio.h>
#include "headers/memoryOps.h"
#include "headers/data.h"
#include "headers/stackOps.h"

long data[DATA_SPACE];
char *data_pointer = (char*)data;  // point to start of data space

int main(void)
{
    printf("=== TESTING STORE/FETCH/COMMA ===\n");

    // --- Test store/fetch ---
    // We will store 12345 at data[100] and fetch it back

    push(12345);   // x
    push(100);     // a-addr
    store();       // (x a-addr -- )

    push(100);     // a-addr
    fetch();       // (a-addr -- x)

    long result = pop();
    if (result == 12345) {
        printf("STORE/FETCH test passed: got %ld\n", result);
    } else {
        printf("STORE/FETCH test FAILED: got %ld\n", result);
    }

    // --- Test comma ---
    // Reset data_pointer to start
    data_pointer = (char*)data;

    push(42);
    comma();   // reserve one cell and write 42
    push(99);
    comma();   // reserve another cell and write 99

    long *cell0 = (long*)data;
    long *cell1 = (long*)(data + 8/sizeof(long));  // next reserved cell

    if (*cell0 == 42 && *cell1 == 99) {
        printf("COMMA test passed: %ld %ld\n", *cell0, *cell1);
    } else {
        printf("COMMA test FAILED: %ld %ld\n", *cell0, *cell1);
    }

    return 0;
}
