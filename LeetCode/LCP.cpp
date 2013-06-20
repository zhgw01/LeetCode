//
//  LCP.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 5/20/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "LCP.h"

using namespace std;

void LCP::run()
{
    cout <<"Run Longest Common Prefix" <<endl;
    
}


bool LCP::isEqualAtIndex(vector<string>& strs, size_t index)
{
    size_t n_strs = strs.size();
    if (n_strs == 0) {
        return true;
    }
    
    char c = strs[0][index];
    for (size_t i = 1; i < n_strs; ++i) {
        if (index >= strs[i].size() || c != strs[i][index]) {
            return false;
        }
    }
    
    return true;
}

string LCP::longestCommonPrefix(std::vector<std::string> &strs)
{
    string result;
    
    if (strs.size() == 0) {
        return result;
    }
    
    size_t n_string = strs[0].size();
    
    for (size_t i = 0; i < n_string; ++i) {
        if (isEqualAtIndex(strs, i)) {
            result.push_back(strs[0][i]);
        }
        else
            break;
    }
    
    return result;
}