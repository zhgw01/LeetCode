//
//  RotateImage.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/25/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "RotateImage.h"

using namespace std;

void RotateImage::run()
{
    cout<<"Run RotateImage"<<endl;
}

void RotateImage::test1()
{
}


void RotateImage::rotate(std::vector<std::vector<int> > &matrix)
{
    int size = matrix.size();
    
    for (int row = 0; row < size / 2; ++row) {
        
        //rotate the outside circle at
        int startColumn = row;
        int endColumn = size - 1 - row;
        int endRow = endColumn;
        
        for (int column = startColumn; column < endColumn; ++column) {
            //rotate
            int temp = matrix[row][column];
            
            matrix[row][column] = matrix[endRow + startColumn - column][startColumn];
            matrix[endRow + startColumn - column][startColumn] = matrix[endRow][endColumn  + startColumn - column];
            matrix[endRow][endColumn  + startColumn - column] = matrix[row + column - startColumn][endColumn];
            matrix[row + column - startColumn][endColumn] = temp;

        
        }
    }
}