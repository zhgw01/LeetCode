//
//  PalindromeNumber.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 5/13/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "PalindromeNumber.h"

using namespace std;

void PalindromeNumber::run()
{
    cout <<"Run Palindrom Number"<<endl;
}

bool PalindromeNumber::isPalindrome(int x)
{
    if (x < 0)
        return false;
    
    int result = 0;
    int y = x;
    while (y > 0) {
        result = result * 10 + y % 10;
        y = y / 10;
    }
    
    if (result == x) {
        return true;
    }
    else
        return false;
}