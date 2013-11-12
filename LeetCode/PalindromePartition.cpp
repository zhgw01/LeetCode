//
//  PalindromePartition.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/12/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "PalindromePartition.h"

using namespace std;

void PalindromePartition::run()
{
    cout<<"Run PalindromePartition"<<endl;
}

void PalindromePartition::test1()
{
}


bool PalindromePartition::isPalindrome(const string &s)
{
    assert(!s.empty());
    
    size_t i = 0;
    size_t j = s.size() - 1;
    
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        
        ++i;
        --j;
    }
    
    return true;
}


vector<vector<string>> PalindromePartition::partition(string s)
{
    vector<vector<string>> result;
    
    for (size_t i = 0, end = s.size(); i < end; ++i) {
        string start = s.substr(0, i + 1);
        if (isPalindrome(start)) {
            string remain = s.substr(i + 1);
            
            if (remain.empty()) {
                vector<string> p;
                p.push_back(start);
                result.push_back(p);
            }
            else {
                vector<vector<string>> subResult = partition(remain);
                
                for (auto it = subResult.begin(); it != subResult.end(); ++it) {
                    vector<string> p;
                    p.push_back(start);
                    p.insert(p.end(), it->begin(), it->end());
                    result.push_back(p);
                }
            }
            
        }
    }
    
    return  result;
}