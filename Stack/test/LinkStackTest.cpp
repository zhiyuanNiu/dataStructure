#include "LinkStack.hpp"
#include <iostream>

int main(){
    LinkStack stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    std::cout << stack.Pop() << stack.Pop() << std::endl;

    return 0;
}