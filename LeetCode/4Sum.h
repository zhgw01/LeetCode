//
//  4Sum.h
//  LeetCode
//
//  Created by Zhang Gongwei on 6/21/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode___Sum__
#define __LeetCode___Sum__

#include "IRun.h"

class FourSum : public IRun
{
public:
    virtual void run();
    
private:
    std::vector<std::vector<int> > fourSum(std::vector<int> &num, int target);
    
    void test1();
    void test2();
    void test3();
    
};

#endif /* defined(__LeetCode___Sum__) */
