//
//  SearchRange.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/6/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "SearchRange.h"

using namespace std;

void SearchRange::run()
{
    cout<<"Run SearchRange"<<endl;
    
    test1();
}

void SearchRange::test1()
{
    
    int A[] = {5, 7, 7, 8, 8, 10};
    int n = sizeof(A) / sizeof(*A);
    int target = 8;
    
    vector<int> result = searchRange(A, n, target);
    assert(result[0] == 3);
    assert(result[1] == 4);
}


vector<int> SearchRange::searchRange(int *A, int n, int target)
{
    vector<int> result;
    result.push_back(-1);
    result.push_back(-1);
    
    if (!A || n == 0) {
        return result;
    }
    
    int low = 0;
    int high = n - 1;
    
    int leftIndex = -1;
    
    //find left index
    while (low <= high) {
        
        if (A[low] == target) {
            leftIndex = low;
            break;
        }
        else if(A[low] > target) {
            break;
        }
        else {
            int mid = (low + high) / 2;
            
            if (A[mid] < target) {
                low = mid + 1;
            }
            else {
                ++low;
                high = mid;
            }
        }
    }
    
    //find right index
    int rightIndex = -1;
    if (leftIndex != -1) {
        low = leftIndex + 1;
        high = n - 1;
        
        while (low <= high) {
            if (A[high] == target) {
                rightIndex = high;
                break;
            }
            //A[high] < target will not happen
            else {
                int mid = (low + high) / 2;
                
                if (A[mid] > target) {
                    high = mid - 1;
                }
                else {
                    --high;
                    low = mid;
                } 
                
            }
        }
        
        if (rightIndex == -1) {
            rightIndex = leftIndex;
        }
    }
    
    result[0] = leftIndex;
    result[1] = rightIndex;
    
    return result;
}