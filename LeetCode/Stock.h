//
//  Stock.h
//  LeetCode
//
//  Created by Zhang Gongwei on 9/8/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__Stock__
#define __LeetCode__Stock__

#include "IRun.h"

class Stock : public IRun
{
public:
    virtual void run();

private:
    void test1();

    int maxProfit(std::vector<int> &prices);
};

#endif /* defined(__LeetCode__Stock__) */
