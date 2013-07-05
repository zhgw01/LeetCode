//
//  LongestValidParentheses.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/5/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "LongestValidParentheses.h"
#include <stack>

using namespace std;

void LongestValidParentheses::run()
{
    cout<<"Run LongestValidParentheses"<<endl;
    
    test2();
}

void LongestValidParentheses::test1()
{
    string s = "()(()";
    
    int expected = 2;
    int result = longestValidParentheses(s);
    
    assert(result == expected);
}

void LongestValidParentheses::test2()
{
    string s = "()()";
    
    int expected = 4;
    int result = longestValidParentheses(s);
    
    assert(result == expected);
}



int LongestValidParentheses::longestValidParentheses(std::string s)
{
    if (s.empty()) {
        return 0;
    }
    
    int result = 0;
    int currentLength = 0;
    
    stack<char> parenthesesStack;
    stack<int> lenStack;
    
    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];
        
        if (parenthesesStack.empty()) {
            if (c == '(') {
                parenthesesStack.push(c);
                lenStack.push(0);
            }
            else {
                if (currentLength > result) {
                    result = currentLength;
                }
                
                currentLength = 0;
            }
                           
        }
        else
        {
            if (c == ')') {
                int len = lenStack.top() + 2;
                lenStack.pop();
                
                if (lenStack.empty()) {
                    currentLength += len;                }
                else {
                    lenStack.top() += len;
                }
                
                parenthesesStack.pop();
            }
            else
            {   lenStack.push(0);
                parenthesesStack.push(c);
            }
        }
        
    }
    
    if (currentLength > result) {
        result = currentLength;
    }

    while (!lenStack.empty()) {
        if (lenStack.top() > result) {
            result = lenStack.top();
        }
        
        lenStack.pop();
    }
    
    
    return result;
}