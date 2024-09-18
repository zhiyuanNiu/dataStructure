/**
 * @file ReversePolishNotation.cpp
 * @author your name (you@domain.com)
 * @brief 将中缀表达式转换为后缀表达式（逆波兰表达式），并计算四则运算表达式的值
 * @version 0.1
 * @date 2024-09-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "LinkStack.hpp"
#include <iostream>
#include <string>
#include <unordered_map>

// 运算符优先级，值越小优先级越高
std::unordered_map<char, int> priority = {{'*', 1}, {'/', 1}, {'+', 2}, {'-', 2}};  


/**
 * @brief 将中序表达式转为后续表达式
 * 1、从左向右遍历中序表达式
 * 2、如果是数字，将数字添加到后续表达式后边
 * 3、如果是运算符，比较运算符和栈顶运算符的优先级，如果当前运算符优先级高，进行入栈；如果当前运算符优先级低，将站内优先级高的运算符出栈然后将当前运算符入栈
 * 4、如果是左括号，入栈；如果是右括号，将栈顶元素出栈直到遇到左括号；
 * 5、遍历到尾部，将站内元素全部出栈
 * 
 * @param expMiddle 
 * @return std::string 
 */
std::string ConvertToRPN(const std::string& expMiddle){
    std::string expRPN = "";
    LinkStack stack;

    for(int i = 0; i < expMiddle.size(); i++){
        char curChar = expMiddle[i];
        if(curChar >= '0' && curChar <= '9'){     // 是数字
            std::string curNum = "";
            while(expMiddle[i] >= '0' && expMiddle[i] <= '9'){      
                curNum += expMiddle[i];
                i++;
            }
            i--;
            expRPN += curNum;
            expRPN += " ";      // 用空格分隔相邻的数字
        }else if(priority.find(curChar) != priority.end()){     // 是运算符
            while(!stack.IsEmpty() && priority.find((char)stack.TopElem()) != priority.end()){
                char top = static_cast<char>(stack.TopElem());
                // char top = (char)stack.TopElem();

                if(priority[top] <= priority[curChar]){
                    stack.Pop();
                    expRPN += top;
                    expRPN += " ";
                }else{
                    break;
                }
            }
            stack.Push((int)curChar);
        }else if(curChar == '('){       // 是 '('
            stack.Push((int)curChar);
        }else if(curChar == ')'){       // 是 ')'
            while((char)stack.TopElem() != '('){
                char top = (char)stack.TopElem();
                stack.Pop();
                expRPN += top;
                expRPN += " ";                
            }
            stack.Pop();    // 弹出 '('
        }
    }

    while(!stack.IsEmpty()){
        char curChar = (int)stack.Pop();
        expRPN += curChar;
        expRPN += " ";
    }

    return expRPN.substr(0, expRPN.size() - 1);
}

/**
 * @brief 计算逆波兰表达式的值
 * 
 * @param expRPN 
 * @return int 
 */
int ComputeRPN(const std::string& expRPN){
    LinkStack stack;
    for(int i = 0; i < expRPN.size(); i++){
        char curChar = expRPN[i];
        if(curChar >= '0' && curChar <= '9'){     // 是数字
            std::string curNum = "";
            while(expRPN[i] >= '0' && expRPN[i] <= '9'){      
                curNum += expRPN[i];
                i++;
            }
            i--;     
            stack.Push(std::stoi(curNum));
        }else if(priority.find(curChar) != priority.end()){     // 是运算符
            int op2 = stack.Pop();
            int op1 = stack.Pop();
            if(curChar == '+')  stack.Push(op1 + op2);
            if(curChar == '-')  stack.Push(op1 - op2);
            if(curChar == '*')  stack.Push(op1 * op2);
            if(curChar == '/')  stack.Push(op1 / op2);
        }
    }

    return stack.TopElem();
}

int main(){
    std::string expMiddle = "9 + (3 - 1) * 3 + 10 / 2";
    std::cout << "compute expression: " << expMiddle << std::endl;

    std::string expRPN = ConvertToRPN(expMiddle);       // 将中序表达式转换为后续表达式
    std::cout << "convert to RPN expression: " << expRPN << std::endl;
    int ans = ComputeRPN(expRPN);          // 计算后续表达式的值
    std::cout << expMiddle << " = " << ans << std::endl;

    return 0;
}


