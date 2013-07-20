//
//  RainWater.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/20/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "RainWater.h"

using namespace std;

void RainWater::run()
{
    cout<<"Run RainWater"<<endl;
    
    test2();
}

void RainWater::test1()
{
    int A[] = {9, 1, 0};
    int n = sizeof(A) / sizeof(*A);
    
    int result = trap(A, n);
    
    int expected = 0;
    
    assert(result == expected);
}

void RainWater::test2()
{
    int A[] = {9, 6, 8, 8, 5, 6, 3};
    int n = sizeof(A) / sizeof(*A);
    
    int result = trap(A, n);
    
    int expected = 3;
    
    assert(result == expected);
}



int RainWater::trap(int *A, int n)
{
    int result = 0;
    
    int leftHeight = 0;
    int leftIndex = 0;
    int sum = 0;
    
    for (int i = 0; i < n; ++i) {
        
        if (A[i] >= leftHeight || i == n - 1) {
            
            
            if (i == n - 1 && A[n - 1] < leftHeight) {
                
                int rightIndex = n - 1;
                int j = rightIndex - 1;
                while (j > leftIndex) {
                    
                    if (A[j] < A[rightIndex]) {
                        result += A[rightIndex] - A[j];
                    }
                    else
                        rightIndex = j;
                    
                    --j;
                    
                }
                
                
            }
            else {
                result += sum;
                leftHeight = A[i];
                leftIndex = i;
                sum = 0;
            }

        }
        else if(leftHeight > 0) {
            sum += leftHeight - A[i];
        }
    }
    
    
    return result;
}