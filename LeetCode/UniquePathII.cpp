//
//  UniquePathII.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/29/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "UniquePathII.h"
#include "ArrayUtil.h"

using namespace std;

void UniquePathII::run()
{
    cout<<"Run UniquePathII"<<endl;
    test1();
}

void UniquePathII::test1()
{
    vector<int> row(5, 0);
    vector<vector<int> > obstacle(4, row);
    
    obstacle[0][1] = 1;
    obstacle[1][0] = 1;
   
    int result = uniquePathsWithObstacles(obstacle);
    int expected = 5;
    assert(result = expected);
}

int UniquePathII::uniquePathsWithObstacles(std::vector<std::vector<int> > &obstacleGrid)
{
    int m = obstacleGrid.size();
    if (m == 0) {
        return 0;
    }
    
    int n = obstacleGrid[0].size();
    if (n == 0) {
        return 0;
    }
    
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }
    
    vector<int> column(n, 1);
    vector<vector<int> > f(m, column);
    
    for (int i = 1; i < n; ++i) {
        
        if (obstacleGrid[0][i] == 1) {
            for (int j = i; j < n; ++j) {
                f[0][j] = 0;
            }
            break;
        }
    }
    
    for (int i = 1; i < m; ++i) {
        
        if (obstacleGrid[i][0] == 1) {
            for (int j = i; j < m; ++j) {
                f[j][0] = 0;
            }
            break;
        }
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 1) {
                f[i][j] = 0;
            }
            else
                f[i][j] = f[i -1][j] + f[i][j-1];
        }
    }
    
    return f[m-1][n-1];
    
}