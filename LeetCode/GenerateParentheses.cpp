//
//  GenerateParentheses.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 6/23/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "GenerateParentheses.h"

using namespace std;

void GenerateParentheses::run()
{
    cout << "Run Generate Parentheses" <<endl;
    
    test1();
}

void GenerateParentheses::test1()
{
    int n = 3;
    
    vector<string> result = generateParenthesis(n);
    
    assert(result.size() == 5);
}

void GenerateParentheses::test2()
{
    int n = 2;
    vector<string> result = generateParenthesis(n);
    
    assert(result.size() == 2);
}


vector<string> GenerateParentheses::generateParenthesis(int n)
{
    vector<string> result;
    
    if (n <= 0) {
        result.push_back("");
        return result;
    }
    
    if (n == 1) {
        result.push_back("()");
        return result;
    }
    
    //the left most parent number
    for (int i = 0; i < n; ++i) {
        vector<string> left = generateParenthesis(i);
        vector<string> right = generateParenthesis(n - i -1);
        
        //combination
        for (size_t j = 0; j < left.size(); ++j) {
            string s_left = "(" + left[j] + ")";
            for (size_t k = 0 ; k < right.size(); ++k) {
                string s = s_left + right[k];
                result.push_back(s);
            }
        }
    }
    
    return result;
}