//
//  ValidParentheses.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 6/23/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "ValidParentheses.h"

#include <stack>

using namespace std;


void Parentheses::run()
{
    cout<<"Run Valid Parentheses"<<endl;
    
    test1();
}

void Parentheses::test1()
{
    string s = "()[]{}";
    
    bool result = isValid(s);
    bool expected = true;
    
    assert(result == expected);
}

bool isMatch(char s, char d)
{
    switch (s)
    {
        case '(':
            return  d == ')';
            
        case '[':
            return d == ']';
            
        case '{':
            return  d == '}';
            
        default:
            return false;
    }
    
    return false;
}

bool Parentheses::isValid(std::string s)
{
    if (s.empty()) {
        return true;
    }
    
    stack<char> parenthesesStack;
    
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (parenthesesStack.empty()) {
            parenthesesStack.push(c);
        }
        else {
            if (isMatch(parenthesesStack.top(), c))
                parenthesesStack.pop();
            else
                parenthesesStack.push(c);
        }
    }
    
    return parenthesesStack.empty();
    
}