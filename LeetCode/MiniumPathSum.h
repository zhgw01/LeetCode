//
//  MiniumPathSum.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/29/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__MiniumPathSum__
#define __LeetCode__MiniumPathSum__

#include "IRun.h"

class MiniumPathSum : public IRun
{
public:
    virtual void run();

private:
    void test1();

    int minPathSum(std::vector<std::vector<int> > &grid);
};

#endif /* defined(__LeetCode__MiniumPathSum__) */
