//
//  MiniumPathSum.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/29/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "MiniumPathSum.h"

using namespace std;

void MiniumPathSum::run()
{
    cout<<"Run MiniumPathSum"<<endl;
}

void MiniumPathSum::test1()
{
}


int MiniumPathSum::minPathSum(std::vector<std::vector<int> > &grid)
{
    int m = grid.size();
    if (m == 0)
        return 0;
    
    int n = grid[0].size();
    if (n == 0)
        return 0;
    
    vector<int> col(n, 0);
    vector<vector<int> > sum(m, col);
    
    sum[0][0] = grid[0][0];
    
    //first row
    for (int j = 1; j < n; ++j) {
        sum[0][j] = sum[0][j - 1] + grid[0][j];
    }
    
    //firt column
    for (int i = 1; i < m; ++i) {
        sum[i][0] = sum[i -1][0] + grid[i][0];
    }
    
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            int minPath = std::min(sum[i -1][j], sum[i][j-1]);
            sum[i][j] = minPath + grid[i][j];
        }
    }
    
    return sum[m -1][n -1];
}