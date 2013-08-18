//
//  MaximumDepth.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/18/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__MaximumDepth__
#define __LeetCode__MaximumDepth__

#include "IRun.h"
#include "Tree.h"

class MaximumDepth : public IRun
{
public:
    virtual void run();

private:
    void test1();

    int maxDepth(TreeNode *root);
};

#endif /* defined(__LeetCode__MaximumDepth__) */
