#include "StaticLinkList.hpp"
#include <iostream>


int main(){
    StaticLinkList staticList(10);
    std::cout << "Initial StaticLinkList: \n" << staticList << std::endl;

    staticList.PushBack(5);
    staticList.PushBack(10);
    staticList.PushBack(15);
    std::cout << "PushBack: \n" << staticList << std::endl;

    staticList.InsertNode(2, 8);
    std::cout << "Insert: \n" << staticList << std::endl;

    staticList.DeleteNode(2);
    std::cout << "Delete: \n" << staticList << std::endl;

    return 0;
}