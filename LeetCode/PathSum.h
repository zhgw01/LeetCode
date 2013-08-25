//
//  PathSum.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/25/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__PathSum__
#define __LeetCode__PathSum__

#include "IRun.h"
#include "Tree.h"

class PathSum : public IRun
{
public:
    virtual void run();

private:
    void test1();

    bool hasPathSum(TreeNode *root, int sum);
};

#endif /* defined(__LeetCode__PathSum__) */
