//
//  MaximumSubArray.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/27/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "MaximumSubArray.h"

using namespace std;

void MaximumSubArray::run()
{
    cout<<"Run MaximumSubArray"<<endl;
}

void MaximumSubArray::test1()
{
}


int MaximumSubArray::maxSubArray(int *A, int n)
{
    int sum = 0;
    int maxSum = -INT32_MIN;
    
    for (int i = 0; i < n; ++i) {
        
        sum += A[i];
        if (sum > maxSum) {
            maxSum = sum;
        }
        
        if (sum < 0)
            sum = 0;
        
    }
    
    return maxSum;
}