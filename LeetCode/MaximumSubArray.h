//
//  MaximumSubArray.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/27/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__MaximumSubArray__
#define __LeetCode__MaximumSubArray__

#include "IRun.h"

class MaximumSubArray : public IRun
{
public:
    virtual void run();

private:
    void test1();

    int maxSubArray(int A[], int n);
};

#endif /* defined(__LeetCode__MaximumSubArray__) */
