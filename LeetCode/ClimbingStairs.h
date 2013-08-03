//
//  ClimbingStairs.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/3/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__ClimbingStairs__
#define __LeetCode__ClimbingStairs__

#include "IRun.h"

class ClimbingStairs : public IRun
{
public:
    virtual void run();

private:
    void test1();

    int climbStairs(int n);
};

#endif /* defined(__LeetCode__ClimbingStairs__) */
