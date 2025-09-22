#ifndef EXECUTIONOPS_H

extern char * execution_pointer;

// This would be easier in assembly, which is ironic
// Actually, maybe I could do
// *(pop())()
// ^ takes the value of where the top of the stack points to and executes it as a function
// It might yell about type, though
// And I am not sure how I would push the right address onto the stack
void execute(void);

#endif
