#include "includes/LinkedListStack.h"

int main(){
    LinkedListStack stack;
    for(int i = 1; i < 10; i++){
        stack.push(i);
    }
    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();
    return 0;
}