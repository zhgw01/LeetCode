//
//  SpiralMatrix.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/27/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__SpiralMatrix__
#define __LeetCode__SpiralMatrix__

#include "IRun.h"

class SpiralMatrix : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();

    std::vector<int> spiralOrder(std::vector<std::vector<int> > &matrix);
};

#endif /* defined(__LeetCode__SpiralMatrix__) */
