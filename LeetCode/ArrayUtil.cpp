//
//  ArrayUtil.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/4/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "ArrayUtil.h"

using namespace std;


bool ArrayUtil::equalToArray(const std::vector<int> &v, int *a, int n)
{
    if (v.size() != n) {
        return false;
    }
    
    for (int i = 0; i < n; ++i) {
        if (v[i] != a[i]){
            return false;
        }
    }
    
    return true;
}