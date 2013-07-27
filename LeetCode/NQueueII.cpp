//
//  NQueueII.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/27/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "NQueueII.h"
#include <set>

using namespace std;

void NQueueII::run()
{
    cout<<"Run NQueueII"<<endl;
    test1();
}

void NQueueII::test1()
{
    int n = 12;
    
    int result = totalNQueens(n);
    int expected = 14200;
    
    assert(result == expected);
}

bool valid(const vector<int>& checkbox, int row)
{
    if (row > checkbox.size()) {
        return true;
    }
    
    
    int col = checkbox[row];
    for (int r = 0; r < row; ++r) {
        //check col coincide
        if (checkbox[r] == col) {
            return false;
        }
        
        //check diagonal coincide
        int diffRow = abs(row - r);
        int diffCol = abs(col - checkbox[r]);
        if (diffRow == diffCol) {
            return false;
        }
    }
    
    return true;
}

//cut
int nextCol(set<int>& mask, int start, int n)
{
    for (int i = start; i < n; ++i) {
        if (mask.insert(i).second) {
            return i;
        }
    }
    
    return n - 1;
}


int NQueueII::totalNQueens(int n)
{
    int result = 0;
    
    //when we reach each row, we will try place position at col 0 first
    vector<int> checkbox(n, 0);
    int row = 0;
    bool forward = true;
    set<int> mask;
    mask.insert(0);
    
    while (row >= 0) {
        //visit child row first
        if (forward) {
            if (valid(checkbox, row)) {
                //found a solution
                if (row == n -1) {
                    ++result;
                    forward = false;
                }
                else {
                    ++row;
                    checkbox[row] = nextCol(mask, 0, n);
                }
            }
            else {
                forward = false;
            }
        }
        //backtrace
        else {
            if (checkbox[row] < n - 1) {
                int prevCol = checkbox[row];
                checkbox[row] = nextCol(mask, prevCol + 1, n);
                mask.erase(prevCol);
                forward = true;
            }
            else {
                mask.erase(checkbox[row]);
                //checkbox[row] = 0;
                --row;
            }
        }
    }
    
    
    return result;
}

bool check(int row, int* place)
{
    for (int i = 0; i < row; ++i)
    {
        int diff = abs(place[i] - place[row]);
        if (diff == 0 || diff == row - i)
            return false;
    }
    return true;
}

void placeQueens(int row, int n, int &count, int* place)
{
    if (row == n)
    {
        ++count;
        return;
    }
    
    for (int i = 0; i < n; ++i)
    {
        place[row] = i;
        if (check(row, place))
            placeQueens(row+1, n, count, place);
    }
}

int totalNQueens2(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int* place = new int[n];
    int count = 0;
    placeQueens(0, n, count, place);
    return count;
}
