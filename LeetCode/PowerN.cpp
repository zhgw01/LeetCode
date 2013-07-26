//
//  PowerN.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/26/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "PowerN.h"

#include <cmath>

using namespace std;

void PowerN::run()
{
    cout<<"Run PowerN"<<endl;
    test1();
}

void PowerN::test1()
{
    double x = 2.0;
    int n = -1;
    
    double result = pow(x, n);
    double expect = 0.5;
    
    double diff = abs(result - expect);
    assert(diff < 0.000001);
}

double PowerN::pow(double x, int n)
{
    bool minus = false;
    if (n < 0) {
        minus = true;
        n = -n;
    }
    double result = 1;
    
    if (n == 0) {
        return result;
    }
    
    
    double y = pow(x, n / 2);
    result = y * y;
    if (n % 2 != 0) {
        result *= x;
    }
    
    return minus ? 1.0 /result : result;
}