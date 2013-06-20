//
//  3SumClosest.h
//  LeetCode
//
//  Created by Zhang Gongwei on 6/20/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode___SumClosest__
#define __LeetCode___SumClosest__

#include "IRun.h"

class ThreeSumClosest : public IRun
{
public:
    
    virtual void run();
    
private:
    int threeSumClosest(std::vector<int> &num, int target);
    
    void test1();
    void test2();
    
};

#endif /* defined(__LeetCode___SumClosest__) */
