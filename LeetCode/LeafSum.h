//
//  LeafSum.h
//  LeetCode
//
//  Created by Zhang Gongwei on 9/25/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__LeafSum__
#define __LeetCode__LeafSum__

#include "IRun.h"
#include "Tree.h"

class LeafSum : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    int sumNumbers(TreeNode *root);

};

#endif /* defined(__LeetCode__LeafSum__) */
