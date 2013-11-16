//
//  GasStation.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/16/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__GasStation__
#define __LeetCode__GasStation__

#include "IRun.h"

using std::vector;

class GasStation : public IRun
{
public:
    virtual void run();

private:
    void test1();

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost);
};

#endif /* defined(__LeetCode__GasStation__) */
