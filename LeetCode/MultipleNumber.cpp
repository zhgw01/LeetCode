//
//  MultipleNumber.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 9/24/14.
//  Copyright (c) 2014 Zhang Gongwei. All rights reserved.
//
//http://blog.csdn.net/sunnyyoona/article/details/39473769
//

#include "MultipleNumber.h"

using namespace std;

void MultipleNumber::run()
{
    cout<<"Run MultipleNumber"<<endl;
    test1();
}

void MultipleNumber::test1()
{
    vector<int> number = {1,2,2};
    
    vector<int> expected = {0, 2};
    vector<int> result = nonUnique(number);
    
    assert(expected == result);
}


vector<int> MultipleNumber::nonUnique(std::vector<int> &number)
{
    vector<int> result;
    size_t n = number.size();
    
    //a[i]原来存的值是x，但用a[i]来统计i值出现的次数k，i每出现一次，就在a[i]原来的值加n, 最后a[i]=x + kn
    //每次加n的好处是，虽然a[i]用来统计i，但通过a[i]%n还是可以得到真正存储的值x
    for (size_t i = 0 ;i < n; ++i) {
        number[number[i]%n] += n;
    }
  
    for (int i = 0; i < n; ++i) {
        if (number[i] / n != 1) {
            result.push_back(i);
        }
    }
    
    return result;
}