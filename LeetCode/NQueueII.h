//
//  NQueueII.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/27/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__NQueueII__
#define __LeetCode__NQueueII__

#include "IRun.h"

class NQueueII : public IRun
{
public:
    virtual void run();

private:
    void test1();

    int totalNQueens(int n);
};

#endif /* defined(__LeetCode__NQueueII__) */
