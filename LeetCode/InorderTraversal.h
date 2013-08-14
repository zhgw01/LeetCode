//
//  InorderTraversal.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/10/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__InorderTraversal__
#define __LeetCode__InorderTraversal__

#include "IRun.h"
#include "Tree.h"

class InorderTraversal : public IRun
{
public:
    virtual void run();

public:
    void test1();

    std::vector<int> inorderTraversal(TreeNode *root);
    std::vector<int> inorderTraversalWithStack(TreeNode *root);

};

#endif /* defined(__LeetCode__InorderTraversal__) */
