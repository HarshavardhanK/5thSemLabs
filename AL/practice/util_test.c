#include "queue.h"
#include "stack.h"

void test_queue() {

}

void test_stack() {

    Stack* stack = init_stack(10);

    for(int i = 0; i < 10; i++)
        push(stack, i + 1);
    
    print_stack(stack);
    
}

int main() {
    test_stack();
}