//
//  PascalTriangleII.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 9/7/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "PascalTriangleII.h"

using namespace std;

void PascalTriangleII::run()
{
    cout<<"Run PascalTriangleII"<<endl;
    test1();
}

void PascalTriangleII::test1()
{
    int row = 3;
    vector<int> expected = {1, 3, 3, 1};
    
    vector<int> result = getRow(row);
    assert(result == expected);
}


std::vector<int> PascalTriangleII::getRow(int rowIndex)
{
    if (rowIndex < 0) {
        return vector<int>();
    }
    
    vector<int> result(rowIndex + 1, 1);
    for (int row = 1; row <= rowIndex; ++row) {
        for (int col = row - 1; col > 0; --col) {
            result[col] += result[col - 1];
        }
    }
    
    return result;
}

std::vector<int> PascalTriangleII::getRow2(int rowIndex)
{
    vector<int> result;
    
    for (int i = 0; i <= rowIndex; ++i) {
        for (int j = i - 1; j > 0; --j) {
            result[j] = result[j] + result[j-1];
        }
        result.push_back(1);
    }
    
    return result;
}


std::vector<int> PascalTriangleII::getRow3(int rowIndex)
{
    vector<int> firstRow(1,1);
    vector<int> sencondRow(1,1);
        
    vector<int>* lastRow = &firstRow;
    vector<int>* nextRow = &sencondRow;
    
    for (int i = 2; i <= rowIndex; ++i) {
        int num = lastRow->size();
        nextRow->clear();
        nextRow->push_back(1);
        for (int j = 0; j < num - 1; ++j) {
            nextRow->push_back((*lastRow)[j] + (*lastRow)[j+1]);
        }
        nextRow->push_back(1);
        
        swap(lastRow, nextRow);
    }
    
    return *nextRow;
}







