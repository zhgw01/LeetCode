//
//  JumpGame.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/23/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__JumpGame__
#define __LeetCode__JumpGame__

#include "IRun.h"

class JumpGame : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();


    int jump(int A[], int n);
};

#endif /* defined(__LeetCode__JumpGame__) */
