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
}

void PascalTriangle::test1()
{
}


vector<vector<int> > PascalTriangle::generate(int numRows)
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