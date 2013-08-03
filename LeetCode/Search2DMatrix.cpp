//
//  Search2DMatrix.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/3/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "Search2DMatrix.h"
#include "ArrayUtil.h"

using namespace std;

void Search2DMatrix::run()
{
    cout<<"Run Search2DMatrix"<<endl;
    test1();
}

void Search2DMatrix::test1()
{
    int A[] = {1, 3, 5, 7};
    int na = sizeof(A) / sizeof(*A);
    int B[] = {10, 11, 16, 20};
    int nb = sizeof(B) / sizeof(*B);
    int C[] = {23, 30, 34, 50};
    int nc = sizeof(C) / sizeof(*C);
    
    vector<int> va = ArrayUtil::createFromArray(A, na);
    vector<int> vb = ArrayUtil::createFromArray(B, nb);
    vector<int> vc = ArrayUtil::createFromArray(C, nc);
    
    vector<vector<int> > matrix;
    matrix.push_back(va);
    matrix.push_back(vb);
    matrix.push_back(vc);
    
    int target = 3;
    
    bool result = searchMatrix(matrix, target);
    bool expected = true;
    
    assert(result == expected);

}


int getValue(int x, const vector<vector<int> >& matrix, int m, int n)
{
    int row = x / n;
    int col = x % n;
    
    if (row < m) {
        return matrix[row][col];
    }
    else
        //error
        return 0;
}

bool Search2DMatrix::searchMatrix(std::vector<std::vector<int> > &matrix, int target)
{
    bool result = false;
    
    size_t m = matrix.size();
    if (m == 0) {
        return result;
    }
    
    size_t n = matrix[0].size();
    if (n == 0) {
        return result;
    }
    
    int total = m * n;
    int low = 0;
    int high = total - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int val = getValue(mid, matrix, m, n);
        
        if (val < target) {
            low = mid + 1;
        }
        else if (val == target) {
            return true;
        }
        else {
            high = mid - 1;
        }
            
    }
    
    
    
    return result;
}