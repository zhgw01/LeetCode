//
//  StockII.h
//  LeetCode
//
//  Created by Zhang Gongwei on 9/14/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__StockII__
#define __LeetCode__StockII__

#include "IRun.h"

class StockII : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    int maxProfit(std::vector<int> &prices);
    int maxProfit2(std::vector<int> &prices);

};

#endif /* defined(__LeetCode__StockII__) */
