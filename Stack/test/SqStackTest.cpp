#include "SqStack.hpp"

int main(){
    SqStack stack(3);

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);

    for(int i = 0; i < 4; i++){
        std::cout << stack.Pop() << std::endl;
    }
    
    return 0;
}