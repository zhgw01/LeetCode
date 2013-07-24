//
//  JumpGameDetermine.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "JumpGameDetermine.h"

using namespace std;

void JumpGameDetermine::run()
{
    cout<<"Run JumpGameDetermine"<<endl;
    test2();
}

void JumpGameDetermine::test1()
{
    int A[] = {2, 3, 1, 1, 4};
    int n = sizeof(A) /sizeof(*A);
    
    bool result = canJump(A, n);
    bool expected = true;
    
    assert(result == expected);
}


void JumpGameDetermine::test2()
{
    
    int A[] = {3, 2, 1, 0, 4};
    int n = sizeof(A) /sizeof(*A);
    
    bool result = canJump(A, n);
    bool expected = false;
    
    assert(result == expected);
}

bool JumpGameDetermine::canJump(int *A, int n)
{
    
    int target = n - 1;
    while (target > 0) {
        int lastStep = target;
        //find mimium step if possible
        for (int i = target - 1; i >= 0; --i) {
            if(i + A[i] >= target)
                lastStep = i;
        }
        
        //no way to jump to target
        if (lastStep == target)
            return false;
        
        target = lastStep;
    }
    
    
    return true;
}