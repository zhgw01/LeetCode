//
//  ClimbingStairs.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/3/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "ClimbingStairs.h"

using namespace std;

void ClimbingStairs::run()
{
    cout<<"Run ClimbingStairs"<<endl;
    test1();
}

void ClimbingStairs::test1()
{
    int n = 2;
    
    int result = climbStairs(n);
    int expected = 2;
    
    assert(result == expected);
}


int ClimbingStairs::climbStairs(int n)
{
    if (n == 0) {
        return 0;
    }
    
    vector<int> steps(n + 1, 1);
    
    //Initialization
    steps[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        steps[i] = steps[i - 2] + steps[i-1];
 
    }
    
    return steps[n];
}