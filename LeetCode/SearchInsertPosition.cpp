//
//  SearchInsertPosition.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/6/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "SearchInsertPosition.h"

using namespace std;

void SearchInsertPosition::run()
{
    cout<<"Run SearchInsertPosition"<<endl;
    
    test1();
}

void SearchInsertPosition::test1()
{
    int A[] = {1,2,5,6};
    int n = sizeof(A) / sizeof(*A);
    int target = 7;
    
    int result = searchInsert(A, n, target);
    int expected = 4;
    
    assert(result == expected);
}


int SearchInsertPosition::searchInsert(int *A, int n, int target)
{
    int result = -1;
    
    if (!A || n == 0) {
        return result;
    }
    
    int low = 0;
    int high = n -1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (A[mid] < target) {
            low = mid + 1;
        }
        else if(A[mid] == target)
            return mid;
        else
            high = mid - 1;
    }
    
    result = low;
    
    return result;
}