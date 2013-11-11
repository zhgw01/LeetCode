  //
//  TwoDRegion.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/11/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "TwoDRegion.h"

using namespace std;

void TwoDRegion::run()
{
    cout<<"Run TwoDRegion"<<endl;
}

void TwoDRegion::test1()
{
}

void TwoDRegion::change(vector<vector<char> > &board, int i, int j)
{
    if (i >= board.size() || i < 0 ||
        j >= board[0].size() || j < 0) {
        return;
    }
    
    if (board[i][j] == 'O') {
        board[i][j] = '#';
        
        change(board, i - 1, j);
        change(board, i + 1, j);
        change(board, i, j - 1);
        change(board, i, j + 1);
    }
}

void TwoDRegion::solve(vector<vector<char> > &board)
{
    if (board.empty()) {
        return;
    }
    
    size_t row = board.size();
    size_t column = board[0].size();
    
    //start from the boarder size, detect 'O' in the four border edge and any 'O' can
    //be DFS from them, these are the 'O' that cannot be surrounded by 'X'
    
    //top & bottom
    for (int j = 0; j < column; ++j) {
        change(board, 0, j);
        change(board, static_cast<int>(row) - 1, j);
    }
    
    
    //left & right
    for (int i = 1; i < row; ++i) {
        change(board, i, 0);
        change(board, i, static_cast<int>(column) - 1);
    }
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
            else if (board[i][j] == '#') {
                board[i][j] = 'O';
            }
        }
    }

}