//
//  SearchRSA.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/6/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "SearchRSA.h"

using namespace std;

void SearchRSA::run()
{
    cout<<"Run Search in Rotated Sorted Array"<<endl;
    
    test3();
}

void SearchRSA::test1()
{
    int A[] = {4,5 ,6, 7, 0, 1, 2};
    int n = sizeof(A) / sizeof(*A);
    int target = 0;
    
    
    int result = search(A, n, target);
    int expected = 4;
    assert(result == expected);
}

void SearchRSA::test2()
{
    
    int A[] = {5, 1, 3};
    int n = sizeof(A) / sizeof(*A);
    int target = 5;
    
    
    int result = search(A, n, target);
    int expected = 0;
    assert(result == expected);

}

void SearchRSA::test3()
{
    int A[] = {8, 9, 2, 3, 4};
    int n = sizeof(A) / sizeof(*A);
    int target = 9;
    
    
    int result = search(A, n, target);
    int expected = 1;
    assert(result == expected);

}


int findPivot(int *A, int n)
{
    int pivot = -1;
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        if (A[low] > A[high]) {
            int mid = (low + high) / 2;
            if (A[mid] > A[high]) {
                low = mid + 1;
            }
            else if(A[mid] < A[low]) {
                ++low;
                high = mid;
            }
        }
        else
        {
            pivot = low;
            break;
        }
    }
    
    
    return pivot;
}

int binaryFind(int *A, int l, int h, int target)
{
    if (l > h || l < 0) {
        return -1;
    }
    
    int result = -1;
    
    while (l <= h) {
        int mid = (l + h) / 2;
        if (A[mid] < target)
            l = mid + 1;
        else if (A[mid] == target)
            return mid;
        else
            h = mid - 1;
    }
    
    return result;
}

int SearchRSA::search(int *A, int n, int target)
{
    int result = -1;
    
    //find pivot first
    int pivot = findPivot(A, n);
    
    assert(pivot >= 0);
    
    
    result = binaryFind(A, 0, pivot - 1, target);
    
    if (result == -1) {
        result = binaryFind(A, pivot, n - 1, target);
    }
    
    return result;
}