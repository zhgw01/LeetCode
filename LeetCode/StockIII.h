//
//  StockIII.h
//  LeetCode
//
//  Created by Zhang Gongwei on 9/14/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__StockIII__
#define __LeetCode__StockIII__

#include "IRun.h"

class StockIII : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();

    int maxProfit(std::vector<int> &prices);
    int maxProfit2(std::vector<int> &prices);
};

#endif /* defined(__LeetCode__StockIII__) */
