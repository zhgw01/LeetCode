//
//  MaxPoints.h
//  LeetCode
//
//  Created by Zhang Gongwei on 12/2/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__MaxPoints__
#define __LeetCode__MaxPoints__

#include "IRun.h"

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class MaxPoints : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    int maxPoints(std::vector<Point>& points);
};

#endif /* defined(__LeetCode__MaxPoints__) */
