//
//  RPN.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 12/4/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "RPN.h"
#include <stack>

using namespace std;

void RPN::run()
{
    cout<<"Run RPN"<<endl;
    test1();
}

void RPN::test1()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    int result = evalRPN(tokens);
    
    assert(result == 9);
}

bool RPN::isOperand(std::string& s)
{
    if (s == "+" || s == "-" ||
        s == "*" || s == "/") {
        return false;
    }
    
    return true;
}

int RPN::evalRPN(vector<string> &tokens)
{
    
    stack<int> operand;
    
    auto it = tokens.begin();
    while (it != tokens.end()) {
        if (isOperand(*it)) {
            operand.push(stoi(*it));
        }
        else {
            int second = operand.top();
            operand.pop();
            int first = operand.top();
            operand.pop();
            
            int value = 0;
            switch ((*it)[0]) {
                case '+':
                    value = first + second;
                    break;
                    
                case '-':
                    value = first - second;
                    break;
                    
                case '*':
                    value = first * second;
                    break;
                    
                case '/':
                    value = first / second;
                    break;
                    
                default:
                    break;
            }
            
            operand.push(value);
        }
        
        ++it;
    }
    
    return operand.top();
 
}