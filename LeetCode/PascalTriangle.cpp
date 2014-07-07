//
//  PascalTriangle.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 9/7/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "PascalTriangle.h"

using namespace std;

void PascalTriangle::run()
{
    cout<<"Run PascalTriangle"<<endl;
    test1();
}

void PascalTriangle::test1()
{
    int rows = 3;
    vector<vector<int>> result = generate(rows);
    
    assert(result.size() == 3);
}

//Rewrite 2014-7-7
vector<vector<int>> PascalTriangle::generate(int numRows)
{
    vector<vector<int>> result;
    
    for (int row = 0; row < numRows; ++row) {
        result.push_back(vector<int>(row + 1, 1));
        
        for (int col = 1; col < row; ++col) {
            result[row][col] = result[row - 1][col - 1] + result[row - 1][col];
        }
    }
    
    return result;
}


vector<vector<int> > PascalTriangle::generate2(int numRows)
{
    vector<vector<int> > result;
    if (numRows < 1) {
        return result;
    }
    
    //push first
    vector<int> firstRow(1, 1);
    result.push_back(firstRow);
    
    for (int i = 1; i <numRows; ++i) {
        vector<int> lastRow = result[i-1];
        vector<int> row;
        row.push_back(1);
        
        for (int j = 0 ; j < lastRow.size() - 1; ++j) {
            row.push_back(lastRow[j] + lastRow[j+1]);
        }
        
        row.push_back(1);
        
        result.push_back(row);
    }
    
    return result;
}