//
//  Triangle.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 9/8/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "Triangle.h"

using namespace std;

void Triangle::run()
{
    cout<<"Run Triangle"<<endl;
    test2();
}

void Triangle::test1()
{
    vector<vector<int> > triangle;
    triangle.push_back(vector<int>(1, -1));
    
    vector<int> row2;
    row2.push_back(-2);
    row2.push_back(-3);
    triangle.push_back(row2);
    
    int result = minimumTotal(triangle);
    int expect = -4;
    
    assert(result == expect);
}

void Triangle::test2()
{
    vector<vector<int> > triangle;
    triangle.push_back(vector<int>(1, -1));
    
    vector<int> row2;
    row2.push_back(3);
    row2.push_back(2);
    triangle.push_back(row2);
    
    vector<int> row3;
    row3.push_back(-3);
    row3.push_back(1);
    row3.push_back(-1);
    triangle.push_back(row3);
    
    int result = minimumTotal(triangle);
    int expect = -1;
    
    assert(result == expect);
}

int Triangle::minimumTotal(vector<vector<int> > &triangle)
{
    size_t numRows = triangle.size();
    if (numRows <= 0) {
        return 0;
    }
    
    vector<int> sums(numRows);
    for (int i = 0; i < numRows; ++i) {
        
        for (int j = i; j > 0; --j) {
            if (j == i || sums[j] > sums[j-1]) {
                sums[j] = sums[j-1];
            }
            
            sums[j] += triangle[i][j];
        }
        
        sums[0] += triangle[i][0];
    }
    
    return *min_element(sums.begin(), sums.end());
}

/*
int Triangle::minimumTotal(vector<vector<int> > &triangle)
{
    size_t numRows = triangle.size();
    if (numRows <= 0) {
        return 0;
    }
    
    vector<vector<int> > sums = triangle;
    
    for (int i = 1; i < numRows; ++i) {
        
        for (int j = 0; j <= i; ++j) {
        
            int lastMin = INT32_MAX;
            if (j < i) {
                lastMin = sums[i-1][j];
            }
            
            if (j > 0 && lastMin > sums[i-1][j-1]) {
                lastMin = sums[i-1][j-1];
            }
            
            if (j < i - 1 && lastMin > sums[i-1][j+1]) {
                lastMin = sums[i-1][j+1];
            }
            
            sums[i][j] += lastMin;
        }

    }
    
    return *min_element(sums[numRows-1].begin(), sums[numRows-1].end());
}
*/