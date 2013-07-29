//
//  UniquePath.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/29/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "UniquePath.h"

using namespace std;

void UniquePath::run()
{
    cout<<"Run UniquePath"<<endl;
    
    test1();
}

void UniquePath::test1()
{
    int m = 1;
    int n = 2;
    
    int result = uniquePaths(m, n);
    int expected = 1;
    
    assert(result == expected);
}



int UniquePath::uniquePaths(int m, int n)
{
    
    vector<int> colum(n, 1);
    vector<vector<int> > f(m, colum);
    
    
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    
    
    
    
    
    return f[m - 1][n -1];
}