/**
 * @file findStringKMP.cpp
 * @author your name (you@domain.com)
 * @brief 给定一个字符串str和一个模式串pattern，找到pattern在str中第一次出现的位置
 * 使用KMP匹配算法
 * @version 0.1
 * @date 2024-09-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string>
#include <iostream>

void getKMP(std::string& pattern, int* kmp)
{
    int i = 0;      // pattern的索引
    int j = 0;      // 当前最长前缀末尾元素的索引

    kmp[0] = -1;
    kmp[1] = 0;

    i = 2;
    while(i < pattern.length())
    {
        if(j == -1 || pattern[i-1] == pattern[j])
        {
            j++;
            kmp[i] = j;
            i++;
        }
        else
            j = kmp[j];
    }

}

int findStrKMP(std::string& str, std::string& pattern)
{

    return ;
}

int main()
{

    return 0;
}