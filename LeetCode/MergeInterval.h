//
//  MergeInterval.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/27/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__MergeInterval__
#define __LeetCode__MergeInterval__

#include "IRun.h"

struct Interval {
         int start;
         int end;
         Interval() : start(0), end(0) {}
         Interval(int s, int e) : start(s), end(e) {}
    
        friend bool operator== (const Interval& lhs, const Interval& rhs);
};

class MergeInterval : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();
    void test3();

    std::vector<Interval> merge(std::vector<Interval> &intervals);
};

#endif /* defined(__LeetCode__MergeInterval__) */
