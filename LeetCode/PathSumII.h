//
//  PathSumII.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/25/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__PathSumII__
#define __LeetCode__PathSumII__

#include "IRun.h"
#include "Tree.h"

class PathSumII : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    std::vector<std::vector<int> > pathSum(TreeNode *root, int sum);

};

#endif /* defined(__LeetCode__PathSumII__) */
