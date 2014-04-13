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
    //test1();
    test2();
}

void ValidPalindrome::test1()
{
    string s("a.");
    
    bool result = isPalindrome(s);
    
    assert(result == true);
}

void ValidPalindrome::test2()
{
    string s("a");
    bool result = isPalindrome(s);
    
    assert(result == true);
}

bool ValidPalindrome::isPalindrome(std::string s)
{
    if (s.empty()) {
        return true;
    }
    
    int start = 0;
    int end = static_cast<int>(s.length()) - 1;
    
    while (start <= end) {
        if (!isalnum(s[start]))
        {
            ++start;
        }
        else if(!isalnum(s[end]))
        {
            --end;
        }
        else if(tolower(s[start]) != tolower(s[end]))
        {
            return false;
        }
        else
        {
            ++start;
            --end;
        }
    }
    
    return true;
}