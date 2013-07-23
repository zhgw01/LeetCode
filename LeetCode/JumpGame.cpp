//
//  JumpGame.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/23/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "JumpGame.h"

using namespace std;

void JumpGame::run()
{
    cout<<"Run JumpGame"<<endl;
    test1();
}

void JumpGame::test1()
{
    int A[] = {2, 3, 1, 1, 4};
    int n = sizeof(A) / sizeof(*A);
    
    int result = jump(A, n);
    int expected = 2;
    
    assert(result == expected);
}

void JumpGame::test2()
{
    int A[] = {1,2, 3};
    int n = sizeof(A) / sizeof(*A);
    
    int result = jump(A, n);
    int expected = 2;

    assert(result == expected);
}


int JumpGame::jump(int *A, int n)
{
    int result = 0;
    
    int target = n - 1;
    
    while (target > 0) {
        
        int lastStep = target;
        //find minimum last step
        int i = target - 1;
        while (i >= 0) {
            if (i + A[i] >= target && i < lastStep) {
                lastStep = i;
            }
            
            --i;
        }
        
        ++result;
        target = lastStep;
    }
     
    return result;
}