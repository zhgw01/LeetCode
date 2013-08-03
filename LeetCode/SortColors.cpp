//
//  SortColors.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/3/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "SortColors.h"

using namespace std;

void SortColors::run()
{
    cout<<"Run SortColors"<<endl;
}

void SortColors::test1()
{
}


void SortColors::sortColors(int *A, int n)
{
    vector<int> count(3, 0);
    
    for (int i = 0; i < n; ++i) {
        ++count[A[i]];
    }

    for (int i = 0; i < count[0]; ++i) {
        A[i] = 0;
    }
    
    for (int i = count[0]; i < count[0] + count[1]; ++i) {
        A[i] = 1;
    }
    
    for (int i = count[0] + count[1]; i < n; ++i) {
        A[i] = 2;
    }
    
    
}