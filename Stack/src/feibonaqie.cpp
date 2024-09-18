/**
 * @file feibonaqie.cpp
 * @author your name (you@domain.com)
 * @brief 计算菲波那切数列的第5位，
 * 斐波那契数列：F(n) = F(n-1) + F(n-2), F(0) = 0, F(1) = 1;
 *  1 1 2 3 5 8 13
 * @version 0.1
 * @date 2024-09-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>

int Feibo(int i){
    if(i < 0){
        std::cerr << "ERROR: the input index is less than 0" << std::endl;
        return -1;
    }
    if(i == 0) return 0;
    if(i == 1) return 1;

    return Feibo(i-1) + Feibo(i-2);
};

int main(){
    int n = 5;
    std::cout << "compute the " << n << "th data of Feibonaqie: \n";

    // 迭代计算
    int* array = new int[n+1];
    array[0] = 0;
    array[1] = 1;
    for(int i = 2; i < n + 1; i++){
        array[i] = array[i-1] + array[i-2];
    }
    std::cout << "iterate result: " << array[n] << std::endl;
    delete array;

    // 递归计算
    std::cout << "recurse result: " << Feibo(n) << std::endl;

    return 0;
}
