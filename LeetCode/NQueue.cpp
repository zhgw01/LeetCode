//
//  NQueue.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/27/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "NQueue.h"

using namespace std;

void NQueue::run()
{
    cout<<"Run NQueue"<<endl;
    
    test3();
}

void NQueue::test1()
{
    int n = 4;
    
    vector<vector<string> > result = solveNQueens(n);
    
    assert(result.size() == 2);
}

void NQueue::test2()
{
    int n = 8;
    
    vector<vector<string> > result = solveNQueens(n);
    
    assert(result.size() == 92);
}

bool valid(vector<string>& solution, int row, int col, int n)
{
    if (row == 0) {
        return true;
    }
    
    //column detect
    for (int i = 0; i < row; ++i) {
        if (solution[i][col] == 'Q') {
            return false;
        }
    }

    //diagonal detect & back-diagonal detect
    for (int i = 0; i < row; ++i) {
        //diagonal
        if (solution[i][i + col - row] == 'Q') {
            return false;
        }
        
        //back diagnoal
        if (solution[i][col + row - i] == 'Q') {
            return false;
        }
    }
    
    
    return true;
}

void searchNext(vector<string>& solution, vector<vector<string> > & result, int row, int n)
{
    if( row == n ) {
        result.push_back(solution);
        return;
    }
    
    for (int col = 0; col < n; ++col) {
        //place in [row, col]
        if (valid(solution, row, col, n)) {
            vector<string> possibleSolution(solution);
            
            string place;
            place.assign(n, '.');
            place[col] = 'Q';
            
            possibleSolution.push_back(place);
            
            searchNext(possibleSolution, result, row + 1, n);
        }
    }
    
    
    
}


std::vector<std::vector<std::string> > NQueue::solveNQueens(int n)
{
    vector<vector<string> > result;
    
       
    vector<string> solution;
    searchNext(solution, result, 0, n);
    
    
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

void placeQueens(int row, int n, int &count, int* place,
                 vector<vector<string> > &result)
{
    if (row == n)
    {
        vector<string> tmp;
        for (int i = 0; i < row; ++i)
        {
            string str(n, '.');
            str[place[i]] = 'Q';
            tmp.push_back(str);
        }
        result.push_back(tmp);
        return;
    }
    
    for (int i = 0; i < n; ++i)
    {
        place[row] = i;
        if (check(row, place))
            placeQueens(row+1, n, count, place, result);
    }
}
vector<vector<string> > solveNQueens2(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int* place = new int[n];
    int count = 0;
    vector<vector<string> > result;
    placeQueens(0, n, count, place, result);
    return result;
}

void print(const vector<string>& result)
{
    cout<<"["<<endl;
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<endl;
    }
    cout<<"]"<<endl;
}

void NQueue::test3()
{
    int n = 8;
    

    
    vector<vector<string> > result = solveNQueens2(n);
    
    vector<vector<string> > myresult = solveNQueens(n);
    
    assert(myresult.size() == 92);
    assert(result.size() == 92);
    
    if (myresult == result) {
        cout<<"maybe  equal"<<endl;
    }
    
    for (int i = 0 ; i < myresult.size(); ++i) {
        if (find(result.begin(), result.end(), myresult[i]) == myresult.end()) {
            print(myresult[i]);
        }
    }
}
