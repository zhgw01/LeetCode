//
//  ValidPalindrome.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 9/14/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "ValidPalindrome.h"

using namespace std;

void ValidPalindrome::run()
{
    cout<<"Run ValidPalindrome"<<endl;
    test1();
}

void ValidPalindrome::test1()
{
    string s("a.");
    
    bool result = isPalindrome(s);
    
    assert(result == true);
}

bool isalhanumeric(char c)
{
    if ('a' <= c && c <= 'z') {
        return true;
    }
    
    if ('A' <= c && c <= 'Z') {
        return true;
    }
    
    if ('0' <= c && c <= '9') {
        return true;
    }
    
    return false;
}

bool ValidPalindrome::isPalindrome(std::string s)
{
    if (s.empty()) {
        return true;
    }
    
    int i = 0;
    int j = s.size() - 1;
    
    while (i <= j) {
        if (!isalhanumeric(s[i])) {
            ++i;
            continue;
        }
        
        if (!isalhanumeric(s[j])) {
            --j;
            continue;
        }
        
        if (tolower(s[i]) != tolower(s[j])) {
            return false;
        }
        
        ++i;
        --j;
    }
    
    return true;
}