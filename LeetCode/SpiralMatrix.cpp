//
//  SpiralMatrix.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/27/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "SpiralMatrix.h"
#include "ArrayUtil.h"

using namespace std;

void SpiralMatrix::run()
{
    cout<<"Run SpiralMatrix"<<endl;
    test2();
}

void SpiralMatrix::test1()
{
    int A[] = {1, 2};
    int na = sizeof(A) / sizeof(*A);
    int B[] = {3, 4};
    int nb = sizeof(B) / sizeof(*B);
    int C[] = {5, 6};
    int nc = sizeof(C) / sizeof(*C);
    
    vector<int> va = ArrayUtil::createFromArray(A, na);
    vector<int> vb = ArrayUtil::createFromArray(B, nb);
    vector<int> vc = ArrayUtil::createFromArray(C, nc);

    vector<vector<int> > matrix;
    matrix.push_back(va);
    matrix.push_back(vb);
    matrix.push_back(vc);
    
    vector<int> result = spiralOrder(matrix);
    
    int D[] = {1,2,4,6,5,3};
    int nd = sizeof(D) / sizeof(*D);
    vector<int> expected = ArrayUtil::createFromArray(D, nd);
    
    assert(result == expected);
}

void SpiralMatrix::test2()
{
    int A[] = {2, 3};
    int na = sizeof(A) / sizeof(*A);
      
    vector<int> va = ArrayUtil::createFromArray(A, na);
  
    vector<vector<int> > matrix;
    matrix.push_back(va);

    
    vector<int> result = spiralOrder(matrix);
    
    int D[] = {2,3};
    int nd = sizeof(D) / sizeof(*D);
    vector<int> expected = ArrayUtil::createFromArray(D, nd);
    
    assert(result == expected);

}

vector<int> SpiralMatrix::spiralOrder(std::vector<std::vector<int> > &matrix)
{
    vector<int> result;
    
    int n = matrix.size();
    
    if (n == 0) {
        return result;
    }
    
    int m = matrix[0].size();
    
    for (int i = 0; i < (n + 1) / 2; ++i) {
        
        int startRow = i;
        int endRow = n - 1 - i;
        int startColumn = i;
        int endColumn = m - 1 - i;
        
        if (endColumn < startColumn) {
            continue;
        }
        
        for (int j = startColumn; j <= endColumn ; ++j) {
            result.push_back(matrix[startRow][j]);
        }
        
        if (endRow > startRow) {
            
            for (int j = startRow + 1; j <= endRow; ++j) {
                result.push_back(matrix[j][endColumn]);
            }
            
            for (int j = endColumn - 1; j >= startColumn; --j) {
                result.push_back(matrix[endRow][j]);
            }
            
            if (endColumn > startColumn) {
                
                for (int j = endRow - 1; j > startRow; --j) {
                    result.push_back(matrix[j][startColumn]);
                }

            }
           
        }
       
    }
    
    return result;
}