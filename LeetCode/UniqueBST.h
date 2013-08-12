//
//  UniqueBST.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/12/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__UniqueBST__
#define __LeetCode__UniqueBST__

#include "IRun.h"

class UniqueBST : public IRun
{
public:
    virtual void run();

private:
    void test1();

    int numTrees(int n);
};

#endif /* defined(__LeetCode__UniqueBST__) */
