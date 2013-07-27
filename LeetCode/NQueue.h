//
//  NQueue.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/27/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__NQueue__
#define __LeetCode__NQueue__

#include "IRun.h"

class NQueue : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();
    void test3();

    std::vector<std::vector<std::string> > solveNQueens(int n);
};

#endif /* defined(__LeetCode__NQueue__) */
