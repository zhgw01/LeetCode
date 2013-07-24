//
//  JumpGameDetermine.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__JumpGameDetermine__
#define __LeetCode__JumpGameDetermine__

#include "IRun.h"

class JumpGameDetermine : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();
    
    bool canJump(int A[], int n);

};

#endif /* defined(__LeetCode__JumpGameDetermine__) */
