//
//  SymmetricTree.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/15/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__SymmetricTree__
#define __LeetCode__SymmetricTree__

#include "IRun.h"
#include "Tree.h"

class SymmetricTree : public IRun
{
public:
    virtual void run();

private:
    void test1();

    bool isSymmetric(TreeNode *root);
};

#endif /* defined(__LeetCode__SymmetricTree__) */
