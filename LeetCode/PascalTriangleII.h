//
//  PascalTriangleII.h
//  LeetCode
//
//  Created by Zhang Gongwei on 9/7/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__PascalTriangleII__
#define __LeetCode__PascalTriangleII__

#include "IRun.h"

class PascalTriangleII : public IRun
{
public:
    virtual void run();

private:
    void test1();

    std::vector<int> getRow(int rowIndex);
    std::vector<int> getRow2(int rowIndex);
    std::vector<int> getRow3(int rowIndex);
};

#endif /* defined(__LeetCode__PascalTriangleII__) */
