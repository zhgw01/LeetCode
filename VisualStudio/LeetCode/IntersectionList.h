#pragma once
#include "stdafx.h"

class LEETCODE_API IntersectionList :
    public IRun
{
public:
    IntersectionList(void);
    ~IntersectionList(void);

    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB);

protected:
    int getListSize(ListNode* head);
    ListNode* advanceList(ListNode* head, int step);
};

