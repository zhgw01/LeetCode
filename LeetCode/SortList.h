//
//  SortList.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/29/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__SortList__
#define __LeetCode__SortList__

#include "IRun.h"
#include "NthNode.h"

class SortList : public IRun
{
public:
    virtual void run();

private:
    void test1();

    ListNode *sortList(ListNode *head);
    ListNode *merge(ListNode* p, ListNode* q);
};

#endif /* defined(__LeetCode__SortList__) */
