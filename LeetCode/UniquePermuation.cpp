//
//  UniquePermuation.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "UniquePermuation.h"
#include "ArrayUtil.h"

using namespace std;

void UniquePermuation::run()
{
    cout<<"Run UniquePermuation"<<endl;
    test1();
}

void UniquePermuation::test1()
{
    int A[] = {1, 1, 2};
    int n = sizeof(A) / sizeof(*A);
    
    vector<int> num = ArrayUtil::createFromArray(A, n);
    
    vector<vector<int> > result = permute(num);
    assert(result.size() == 3);

}

std::vector<vector<int> > UniquePermuation::permute(std::vector<int> &num)
{
    typedef vector<vector<int> > PType;
    PType result;
    
    if (num.size() == 1) {
        result.push_back(num);
        return result;
    }
    
    sort(num.begin(), num.end());
    
    for (int i = 0; i < num.size(); ++i) {
        
        if (i > 0 && num[i] == num[i - 1]) {
            continue;
        }
        
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