//
//  BTPathSum.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__BTPathSum__
#define __LeetCode__BTPathSum__

#include "IRun.h"
#include "Tree.h"

class BTPathSum : public IRun
{
public:
    virtual void run();

private:
    void test1();

    int maxPathSum(TreeNode *root);
};

#endif /* defined(__LeetCode__BTPathSum__) */
