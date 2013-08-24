//
//  FlattenBST.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__FlattenBST__
#define __LeetCode__FlattenBST__

#include "IRun.h"
#include "Tree.h"

class FlattenBST : public IRun
{
public:
    virtual void run();

private:
    void test1();

    void flatten(TreeNode *root);
};

#endif /* defined(__LeetCode__FlattenBST__) */
