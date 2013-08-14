//
//  RecoverBST.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/14/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__RecoverBST__
#define __LeetCode__RecoverBST__

#include "IRun.h"
#include "Tree.h"

class RecoverBST : public IRun
{
public:
    virtual void run();

private:
    void test1();

    void recoverTree(TreeNode *root);
};

#endif /* defined(__LeetCode__RecoverBST__) */
