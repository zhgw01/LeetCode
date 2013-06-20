//
//  3Number.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 6/19/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "3Number.h"
#include <algorithm>

using namespace std;

void ThreeNum::run()
{
    cout<<"Run Three Num";
    
    test2();
}

void ThreeNum::test1()
{
    vector<int> num;
    num.resize(6);
    num[0] = -1;
    num[1] = 0;
    num[2] = 1;
    num[3] = 2;
    num[4] = -1;
    num[5] = -4;
    
    vector<vector<int> > result = threeSum(num);
    assert(result.size() == 2);
    
    assert(result[0][0] == -1);
    assert(result[0][1] == -1);
    assert(result[0][2] == 2);
    
    
    assert(result[1][0] == -1);
    assert(result[1][1] == 0);
    assert(result[1][2] == 1);

}

void ThreeNum::test2()
{
    vector<int> num;
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    
    vector<vector<int> > result = threeSum(num);
    assert(result.size() == 1);
    
    assert(result[0][0] == 0);
    assert(result[0][1] == 0);
    assert(result[0][2] == 0);

}


std::vector<std::vector<int> > ThreeNum::threeSum(std::vector<int> &num)
{
    typedef vector<int> triple;
    vector<triple> result;
    
    sort(num.begin(), num.end());
    
    size_t n_size = num.size();
    for (size_t i = 0; i < n_size; ++i) {
        
        if(i > 0 && num[i] == num[i -1])
            continue;
        
        for (size_t j = i + 1; j < n_size; ++j) {
            if (j > i + 1 && num[j] == num[j - 1])
                continue;
            
            int remain = - (num[i] + num[j]);
            if (binary_search(num.begin() + (j + 1), num.end(), remain)) {
                triple t;
                t.resize(3);
                t[0] = num[i];
                t[1] = num[j];
                t[2] = remain;
                
                result.push_back(t);
            }
        }
    }
    
    return result;
}