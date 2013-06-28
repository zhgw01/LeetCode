//
//  RemoveDuplicate.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 6/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "RemoveDuplicate.h"

using namespace std;

void RemoveDuplicate::run()
{
    cout<<"Run RemoveDuplicate"<<endl;
    
    test1();
}

void RemoveDuplicate::test1()
{
    int a[] = {1, 1, 2};
    
    int result = removeDuplicates(a, sizeof(a) / sizeof(*a));
    
    int expected = 2;
    
    assert(result == expected);
}


int RemoveDuplicate::removeDuplicates(int *A, int n)
{
    if (!A || n == 0) {
        return 0;
    }
    
    int j = 0;
    
    for (int i = 1; i < n; ++i) {
        if (A[i] != A[j]) {
            A[++j] = A[i];
        }
    }
    
    return j + 1;
}