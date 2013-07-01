//
//  DivideInteger.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/1/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "DivideInteger.h"
#include <ctime>
#include <cmath>


using namespace std;

void DivideInteger::run()
{
    cout<<"Run DivideInteger"<<endl;
    test2();
}

void DivideInteger::test1()
{
    int dividen = 2147483647;
    int divisor = 2;
    
    int expected = 1073741823;
    
    clock_t start = clock();
    
    int result = divide2(dividen, divisor);
    
    clock_t end = clock();
    cout<<"divide2 takes " << (end - start) << " ticks" <<endl;
    start = clock();
    
    result = divide(dividen, divisor);
    
    end = clock();
    cout<<"divide takes " << (end - start) << " ticks" <<endl;
    
    assert(expected == result);
}

void DivideInteger::test2()
{
    
    int dividen = -2147483648;
    int divisor = -2147483648;
    
    int expected = 1;
    

    
  
    
    int result = divide(dividen, divisor);
    

    
    assert(expected == result);

}

int DivideInteger::divide(int intDividend, int intDivisor)
{
    long long dividend = intDividend;
    long long divisor = intDivisor;
    
    assert(divisor != 0);
    if (divisor == 0) {
        return 0;
    }
    
    int result = 0;
    bool minus = false;
    
    if (dividend < 0) {
        minus = !minus;
        dividend = -dividend;
    }
    
    if (divisor < 0) {
        minus = !minus;
        divisor = -divisor;
    }
    
    if (divisor == 1) {
        result = dividend;
    }
    else {
        int l = 1;
        long long big = dividend;
        long long maxdivisor = divisor;
        while (big > maxdivisor) {
            l <<= 1;
            maxdivisor <<= 1;
        }

        
        while (l >= 1 ) {
            while (dividend >= maxdivisor) {
                result += l;
                dividend -= maxdivisor;
            }
            maxdivisor >>= 1;
            l >>= 1;
        }
    }
        
    return minus ? -result : result;
}

int DivideInteger::divide2(int dividend, int divisor)
{
    int sign = 1;
    if(dividend < 0)
        sign *= -1;
    if(divisor < 0)
        sign *= -1;
    
    long long big = abs((long long)dividend);
    long long small = abs((long long)divisor);
    long long temp = small;
    long long midres = 1;
    while(temp < big)
    {
        temp <<= 1;
        midres <<= 1;
    }
    
    int ret = 0;
    while(temp >= small)
    {
        while(big >= temp)
        {
            big -= temp;
            ret += midres;
        }
        temp >>= 1;
        midres >>= 1;
    }
    return ret*sign;
}