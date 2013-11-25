//
//  Preorder.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/25/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__Preorder__
#define __LeetCode__Preorder__

#include "IRun.h"
#include "Tree.h"

using std::vector;

class Preorder : public IRun
{
public:
    virtual void run();

private:
    void test1();

    vector<int> preorderTraversal(TreeNode *root);
};

#endif /* defined(__LeetCode__Preorder__) */
