//
//  3SumClosest.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 6/20/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "3SumClosest.h"

using namespace std;


void ThreeSumClosest::run()
{
    cout <<"Run 3 Sum Closest"<<endl;
    test2();
}

void ThreeSumClosest::test1()
{
    vector<int> num;
    num.push_back(-1);
    num.push_back(2);
    num.push_back(1);
    num.push_back(-4);
    
    int target = 1;
    int expected = 2;
    
    int result = threeSumClosest(num, target);
    
    assert(result == expected);
    
}

void ThreeSumClosest::test2()
{
    vector<int> num;
    num.push_back(0);
    num.push_back(2);
    num.push_back(1);
    num.push_back(-3);
    
    int target = 1;
    int expected = 0;
    
    int result = threeSumClosest(num, target);
    
    assert(result == expected);

}

int ThreeSumClosest::threeSumClosest(std::vector<int> &num, int target)
{
    size_t n_size = num.size();
    assert(n_size >= 3);
    
    sort(num.begin(), num.end());
    
    int result = num[0] + num[1] + num[2];
    
    for (size_t i = 0; i < n_size - 2; ++i) {
        int a = num[i];
        if (i != 0 && num[i-1] == a) {
            continue;
        }
        
        size_t k = i + 1;
        size_t n = n_size - 1;
        while (k < n) {
            
            int sum = a + num[k] + num[n];
            int dif = sum - target;
            if (abs(dif) < abs(result - target)) {
                result = sum;
            }
            
            if (dif < 0) {
                ++k;
            }
            else if (dif > 0)
                --n;
            else
                return sum;
            
        }
    }
    
    return result;
   
}