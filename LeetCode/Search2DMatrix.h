//
//  Search2DMatrix.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/3/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__Search2DMatrix__
#define __LeetCode__Search2DMatrix__

#include "IRun.h"

class Search2DMatrix : public IRun
{
public:
    virtual void run();

private:
    void test1();

    bool searchMatrix(std::vector<std::vector<int> > &matrix, int target);
};

#endif /* defined(__LeetCode__Search2DMatrix__) */
