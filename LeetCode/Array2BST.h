//
//  Array2BST.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__Array2BST__
#define __LeetCode__Array2BST__

#include "IRun.h"
#include "Tree.h"

class Array2BST : public IRun
{
public:
    virtual void run();

private:
    void test1();

    TreeNode *sortedArrayToBST(std::vector<int> &num);
};

#endif /* defined(__LeetCode__Array2BST__) */
