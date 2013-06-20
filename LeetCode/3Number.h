//
//  3Number.h
//  LeetCode
//
//  Created by Zhang Gongwei on 6/19/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode___Number__
#define __LeetCode___Number__

#include "IRun.h"
#include <vector>

class ThreeNum : public IRun
{
public:
    virtual void run();
    
private:
    std::vector<std::vector<int> > threeSum(std::vector<int> &num);
    
    void test1();
    void test2();
    
};

#endif /* defined(__LeetCode___Number__) */
