//
//  Candy.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/18/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__Candy__
#define __LeetCode__Candy__

#include "IRun.h"

using std::vector;

class Candy : public IRun
{
public:
    virtual void run();

private:
    void test1();

    int candy(vector<int> &ratings);
};

#endif /* defined(__LeetCode__Candy__) */
