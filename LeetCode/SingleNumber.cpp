//
//  SingleNumber.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/19/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "SingleNumber.h"

using namespace std;

void SingleNumber::run()
{
    cout<<"Run SingleNumber"<<endl;
}

void SingleNumber::test1()
{
}

int SingleNumber::singleNumber(int *A, int n)
{
    int ones=0, twos=0, threes;
    
    for (int i = 0; i < n; ++i) {
        twos |= ones & A[i];
        ones = ones ^ A[i];
        threes = ones & twos;
        ones = ones & ~threes;
        twos = twos & ~threes;
    }
    
    return ones;
}

int SingleNumber::singleNumber2(int *A, int n)
{
    int result = 0;
    int digit[32];
    
    for (int d = 0; d < 32; ++d) {
        for (int i = 0; i < n; ++i) {
            //operate on dth digit
            if (((A[i]>>d) & 1 ) == 1) {
                digit[d] = (digit[d] + 1) % 3;
            }
        }
        
        result |= (digit[d] << d);
    }
    
    return result;
}