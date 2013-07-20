//
//  RainWater.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/20/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__RainWater__
#define __LeetCode__RainWater__

#include "IRun.h"

class RainWater : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();

    int trap(int A[], int n);
};

#endif /* defined(__LeetCode__RainWater__) */
