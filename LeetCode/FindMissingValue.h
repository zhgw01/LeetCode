//
//  FindMissingValue.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/20/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__FindMissingValue__
#define __LeetCode__FindMissingValue__

#include "IRun.h"

class FindMissingValue : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();

int firstMissingPositive(int A[], int n);
};

#endif /* defined(__LeetCode__FindMissingValue__) */
