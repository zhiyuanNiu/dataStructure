/**
 * @file findStringTraverse.cpp
 * @author your name (you@domain.com)
 * @brief 给定一个字符串和一个模式串，找到模式串在字符串中出现的位置：
 * 使用暴力匹配算法，遍历字符串，每次匹配模式串，找到匹配的位置，并记录下来。
 * @version 0.1
 * @date 2024-09-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <string>


int findStr(std::string& str, std::string& pattern)
{
    int i = 0;  // str的索引
    int j = 0;  // pattern的索引

    while(i < str.length() && j < pattern.length())
    {
        if(str[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }

    if(j >= pattern.length())
        return i - j;
    else
        return 0;
}

int main()
{
    std::string str = "goodgoogle";
    std::string pattern = "google";

    std::cout << "find \"" << pattern << "\" in \"" << str << "\" at position: " << findStr(str, pattern) << std::endl;

    return 0;
}