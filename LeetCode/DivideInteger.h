//
//  DivideInteger.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/1/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__DivideInteger__
#define __LeetCode__DivideInteger__

#include "IRun.h"

class DivideInteger : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();

    int divide(int dividend, int divisor);
    int divide2(int dividend, int divisor);
};

#endif /* defined(__LeetCode__DivideInteger__) */
