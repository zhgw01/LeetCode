//
//  ValidateBST.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/14/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__ValidateBST__
#define __LeetCode__ValidateBST__

#include "IRun.h"
#include "Tree.h"

class ValidateBST : public IRun
{
public:
    virtual void run();

private:
    void test1();

    bool isValidBST(TreeNode *root);
    
};

#endif /* defined(__LeetCode__ValidateBST__) */
