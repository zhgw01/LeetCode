//
//  DistincSubSequence.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 9/2/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "DistincSubSequence.h"

using namespace std;

void DistincSubSequence::run()
{
    cout<<"Run DistincSubSequence"<<endl;
    test1();
}

void DistincSubSequence::test1()
{
    string S("b");
    string T("a");
    
    int result = numDistinct(S, T);
    int expected = 0;
    assert(result == expected);
}


int DistincSubSequence::numDistinct(std::string S, std::string T)
{
    size_t n = S.size();
    size_t m = T.size();
    
    if (!n || !m) {
        return 0;
    }
    
    vector<int> occurcence(m+1);
    occurcence[0] = 1;
    
    //transition function f(i,j) = f(i - 1, j) + S[i] == T[j] ? f(i-1, j -1) : 0
    for (int i = 0 ; i < n; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            if (S[i] == T[j]) {
                occurcence[j+1] += occurcence[j];
            }
        }
    }
    
    return occurcence[m];
}