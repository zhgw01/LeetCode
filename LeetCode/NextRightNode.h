//
//  NextRightNode.h
//  LeetCode
//
//  Created by Zhang Gongwei on 9/2/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__NextRightNode__
#define __LeetCode__NextRightNode__

#include "IRun.h"

struct TreeLinkNode {
      int val;
      TreeLinkNode *left, *right, *next;
      TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class NextRightNode : public IRun
{
public:
    virtual void run();

private:
    void test1();

    void connect(TreeLinkNode *root);
};

#endif /* defined(__LeetCode__NextRightNode__) */
