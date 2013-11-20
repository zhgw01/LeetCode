//
//  CopyList.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/20/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__CopyList__
#define __LeetCode__CopyList__

#include "IRun.h"

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class CopyList : public IRun
{
public:
    virtual void run();

private:
    void test1();
 
    RandomListNode *copyRandomList(RandomListNode *head);
};

#endif /* defined(__LeetCode__CopyList__) */
