//
//  Permutation.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "Permutation.h"
#include "ArrayUtil.h"

using namespace std;

void Permutation::run()
{
    cout<<"Run Permutation"<<endl;
    test1();
}

void Permutation::test1()
{
    int A[] = {1, 2, 3};
    int n = sizeof(A) / sizeof(*A);
    
    vector<int> num = ArrayUtil::createFromArray(A, n);
    
    vector<vector<int> > result = permute(num);
    assert(result.size() == 6);
}


vector<vector<int> > Permutation::permute(std::vector<int> &num)
{
    typedef vector<vector<int> > PType;
    PType result;
    
    if (num.size() == 1) {
        result.push_back(num);
        return result;
    }
    
    for (int i = 0; i < num.size(); ++i) {
        vector<int> subNum(num.begin(), num.end());
        subNum.erase(subNum.begin() + i);
        
        PType subResult = permute(subNum);
      
        
        for (int j = 0; j < subResult.size(); ++j) {
            subResult[j].insert(subResult[j].begin(), num[i]);
            result.push_back(subResult[j]);
        }
        
        
    }
    
    
    return result;
}