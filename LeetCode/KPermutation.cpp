//
//  KPermutation.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "KPermutation.h"

using namespace std;

void KPermutation::run()
{
    cout<<"Run KPermutation"<<endl;
    test1();
}

void KPermutation::test1()
{
    int n = 3;
    int k = 4;
    
    string result = getPermutation(n, k);
    string expected = "231";
    
    assert(result == expected);
}


string KPermutation::getPermutation(int n, int k)
{
    string result;
    
    for (int i = 0; i < n; ++i) {
        result.push_back('1' + i);
    }
    
    vector<int> index;
    int factorial = 1;
    int digit = 1;
    
    while (k > factorial) {
        ++digit;
        factorial *= digit;
    }
    
    if (digit > n) {
        return "Invalid";
    }
    
    while (digit > 0) {
        factorial /= digit;
        int m = (k - 1) / factorial;
        index.push_back(m);
        k -= m * factorial;
        --digit;
    }
    
    
    for (int i = 0 ; i < index.size(); ++i) {
        
        if (index[i] == 0) {
            continue;
        }
        
        int pos = n  - index.size() + i;
        int swapPos = pos + index[i];
        
        char temp = result[swapPos];
        for (int j = swapPos; j > pos; --j) {
            result[j] = result[j - 1];
        }
        
        result[pos] = temp;
    }
    
    
    return result;
}