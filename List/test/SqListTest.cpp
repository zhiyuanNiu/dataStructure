#include "SqList.hpp"
#include <vector>
#include <iostream>

int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};

    SqList sqlist(vec);
    std::cout << "初始化:\n" << sqlist << std::endl;

    std::cout << "获取第3个元素: " << sqlist.GetElem(3) << std::endl;

    sqlist.ListDelete(3);   
    std::cout << "删除第3个元素: " << sqlist << std::endl;

    sqlist.ListInsert(3, 10);
    std::cout << "在第3个位置插入元素10: " << sqlist << std::endl;    

    return 0;
}