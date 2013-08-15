//
//  SameTree.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/15/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__SameTree__
#define __LeetCode__SameTree__

#include "IRun.h"
#include "Tree.h"

class SameTree : public IRun
{
public:
    virtual void run();

private:
    void test1();

    bool isSameTree(TreeNode *p, TreeNode *q);
};

#endif /* defined(__LeetCode__SameTree__) */
