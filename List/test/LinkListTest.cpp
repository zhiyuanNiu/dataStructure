#include "LinkList.hpp"
#include <vector>

int main(){
    LinkList list;
    std::cout << "Initial: \n";
    std::cout << list << std::endl;     // LinkList length: 0, {} 

    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    list.InsertEnd(vec);
    std::cout << "InsertEnd: \n";
    std::cout << list << std::endl;     // LinkList length: 6, {1, 2, 3, 4, 5, 6} 

    list.Delete();
    std::cout << "Delete LinkList: \n";
    std::cout << list << std::endl;     // LinkList length: 0, {}     

    list.InsertBegin(vec);
    std::cout << "InsertBegin: \n";
    std::cout << list << std::endl;    // LinkList length: 6, {6, 5, 4, 3, 2, 1} 

    return 0;
}