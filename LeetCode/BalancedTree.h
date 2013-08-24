//
//  BalancedTree.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__BalancedTree__
#define __LeetCode__BalancedTree__

#include "IRun.h"
#include "Tree.h"

class BalancedTree : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    bool isBalanced(TreeNode *root);

};

#endif /* defined(__LeetCode__BalancedTree__) */
