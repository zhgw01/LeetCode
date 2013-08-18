//
//  LevelTraversal.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/18/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__LevelTraversal__
#define __LeetCode__LevelTraversal__

#include "IRun.h"
#include "Tree.h"

class LevelTraversal : public IRun
{
public:
    virtual void run();

private:
    void test1();

    std::vector<std::vector<int> > levelOrder(TreeNode *root);
};

#endif /* defined(__LeetCode__LevelTraversal__) */
