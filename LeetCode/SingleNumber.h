//
//  SingleNumber.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/19/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__SingleNumber__
#define __LeetCode__SingleNumber__

#include "IRun.h"

class SingleNumber : public IRun
{
public:
    virtual void run();

private:
    void test1();

    int singleNumber(int A[], int n);
    int singleNumber2(int A[], int n);
    
};

#endif /* defined(__LeetCode__SingleNumber__) */
