//
//  FindMissingValue.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/20/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "FindMissingValue.h"

using namespace std;

void FindMissingValue::run()
{
    cout<<"Run FindMissingValue"<<endl;
    
    test2();
}

void FindMissingValue::test1()
{
    
    int A[] = {3, 4, -1, 1};
    int n = sizeof(A) / sizeof(*A);
    
    int result = firstMissingPositive(A, n);
    int expected = 2;
    
    assert(result == expected);
}

void FindMissingValue::test2()
{
    int A[] = {1, 1};
    int n = sizeof(A) / sizeof(*A);
    
    int result = firstMissingPositive(A, n);
    int expected = 2;
    
    assert(result == expected);

}

int FindMissingValue::firstMissingPositive(int *A, int n)
{
    int result = n + 1;
    
    for (size_t i = 0; i < n; ++i) {
        
        //put value i in index i - 1
        while(A[i] >= 1 && A[i] <= n && A[i] != i + 1) {
            if (A[i] != A[A[i] - 1]) {
                swap(A[i], A[A[i] - 1]);
            }
            else
                break;
            
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (A[i] != i + 1) {
            result = i + 1;
            return result;
        }
    }
    
    return result;
}