//
//  InsertInterval.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__InsertInterval__
#define __LeetCode__InsertInterval__

#include "IRun.h"
#include "MergeInterval.h"

class InsertInterval : public IRun
{
public:
    virtual void run();

private:
    void test1();

    std::vector<Interval> insert(std::vector<Interval> &intervals, Interval newInterval);
};

#endif /* defined(__LeetCode__InsertInterval__) */
