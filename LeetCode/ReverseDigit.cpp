//
//  ReverseDigit.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 4/22/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "ReverseDigit.h"

using namespace std;


void ReverseDigit::run()
{
    cout<<"Run Reverse Digit"<<endl;
    int x = 123;
    int result = reverse(x);
    int expect = 321;
    assert(result == expect);
}


int ReverseDigit::reverse(int x)
{
    bool minus = x < 0;
    if (minus)
        x = -x;
    
    int result = 0;
    while (x > 0) {
        result = x % 10 + result * 10;
        x /= 10;
    }
    
    return minus ? -result : result;
}