//
//  NextRightNodeII.h
//  LeetCode
//
//  Created by Zhang Gongwei on 9/4/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__NextRightNodeII__
#define __LeetCode__NextRightNodeII__

#include "IRun.h"
#include "NextRightNode.h"

class NextRightNodeII : public IRun
{
public:
    virtual void run();

private:
    void test1();

    void connect(TreeLinkNode *root);
};

#endif /* defined(__LeetCode__NextRightNodeII__) */
