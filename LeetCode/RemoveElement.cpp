//
//  RemoveElement.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 6/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "RemoveElement.h"

using namespace std;

void RemoveElement::run()
{
    cout<<"Run RemoveElement"<<endl;
    
    test1();
}

void RemoveElement::test1()
{

}


int RemoveElement::removeElement(int *A, int n, int elem)
{
    if (!A || n == 0) {
        return 0;
    }
    
    int j = -1;
    
    for (int i = 0; i < n; ++i) {
        if (A[i] != elem) {
            A[++j] = A[i];
        }
    }
    
    
    return j == -1 ? 0 : j + 1;
}