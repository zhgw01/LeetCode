//
//  Triangle.h
//  LeetCode
//
//  Created by Zhang Gongwei on 9/8/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__Triangle__
#define __LeetCode__Triangle__

#include "IRun.h"

using std::vector;

class Triangle : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();

    int minimumTotal(vector<vector<int> > &triangle);
    int minimumTotal2(vector<vector<int> > &triangle);
};

#endif /* defined(__LeetCode__Triangle__) */
