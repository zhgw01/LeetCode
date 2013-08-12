//
//  UniqueBST.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/12/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "UniqueBST.h"

using namespace std;

void UniqueBST::run()
{
    cout<<"Run UniqueBST"<<endl;
    test1();
}

void UniqueBST::test1()
{
    int n = 3;
    
    int result = numTrees(n);
    assert(result == 5);
}


int UniqueBST::numTrees(int n)
{
    if (n == 0 || n == 1) {
        return n;
    }
    
    vector<int> trees;
    trees.resize(n + 1, 0);
    trees[0] = 1;
    trees[1] = 1;
    
    for (int k = 2; k <= n; ++k) {
        
        for (int i = 1; i <= k; ++i) {
            trees[k] += trees[i-1] * trees[k-i];
        }
    }
    
    
    return trees[n];
}