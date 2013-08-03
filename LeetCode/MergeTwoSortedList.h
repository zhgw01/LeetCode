//
//  MergeTwoSortedList.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/3/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__MergeTwoSortedList__
#define __LeetCode__MergeTwoSortedList__

#include "IRun.h"
#include "NthNode.h"

class MergeTwoSortedList : public IRun
{
public:
    virtual void run();

private:
    void test1();

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
};

#endif /* defined(__LeetCode__MergeTwoSortedList__) */
