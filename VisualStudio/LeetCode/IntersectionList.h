#pragma once
#include "stdafx.h"

class LEETCODE_API IntersectionList :
    public IRun
{
public:
    IntersectionList(void);
    ~IntersectionList(void);

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
};

