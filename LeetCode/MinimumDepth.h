//
//  MinimumDepth.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__MinimumDepth__
#define __LeetCode__MinimumDepth__

#include "IRun.h"
#include "Tree.h"

class MinimumDepth : public IRun
{
public:
    virtual void run();

private:
    void test1();

    int minDepth(TreeNode *root);
};

#endif /* defined(__LeetCode__MinimumDepth__) */
