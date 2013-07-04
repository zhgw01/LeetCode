//
//  NextPermutation.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/3/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "NextPermutation.h"
#include "ArrayUtil.h"

using namespace std;

void NextPermutation::run()
{
    cout<<"Run NextPermutation"<<endl;
    test1();
}

void NextPermutation::test1()
{
    int a[] = {2, 3, 1};
    int b[] = {3, 1, 2};
    
    int aSize = sizeof(a) / sizeof(*a);
    int bSize = sizeof(b) / sizeof(*b);
    
    vector<int> num = ArrayUtil::createFromArray(a, aSize);
    nextPermutation(num);
    
    bool expected = ArrayUtil::equalToArray(num, b, bSize);
    
    assert(expected);
}

void NextPermutation::nextPermutation(std::vector<int> &num)
{
    size_t len = num.size();
    
    //find fist break the order
    size_t index = 0;
    for (size_t i = len - 1; i > 0; --i) {
        if (num[i] > num[i-1]) {
            index = i;
            break;
        }
    }
    
    if (index == 0) {
        //reverse the number
        for (size_t i = 0; i < len/2; ++i) {
            swap(num[i], num[len - 1 -i]);
        }
    }
    else {
        size_t smallIndex = index;
        for (size_t i = index + 1; i < len; ++i) {
            if (num[i] > num[index - 1]) {
                smallIndex = i;
            }
        }
        
        swap(num[index - 1], num[smallIndex]);
        size_t subLen = len - index;
        size_t mid = subLen / 2;
        for (size_t i = 0; i < mid; ++i) {
            swap(num[index + i], num[index + subLen - 1 - i]);
        }
    }
    
  
    return;
}