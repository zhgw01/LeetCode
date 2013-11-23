//
//  LinkedListCycleII.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/23/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__LinkedListCycleII__
#define __LeetCode__LinkedListCycleII__

#include "IRun.h"
#include "NthNode.h"

class LinkedListCycleII : public IRun
{
public:
    virtual void run();

private:
    void test1();

    ListNode *detectCycle(ListNode *head);
};

#endif /* defined(__LeetCode__LinkedListCycleII__) */
