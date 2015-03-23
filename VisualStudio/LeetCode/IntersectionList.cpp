#include "stdafx.h"
#include "IntersectionList.h"


IntersectionList::IntersectionList(void)
{
}


IntersectionList::~IntersectionList(void)
{
}

ListNode * IntersectionList::getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int aSize = 0;
    int bSize = 0;

    ListNode* node = headA;
    while (node)
    {
        ++aSize;
        node = node->next;
    }

    node = headB;
    while (node)
    {
        ++bSize;
        node = node->next;
    }

    ListNode* newHeadA = headA;
    ListNode* newHeadB = headB;
    int step = aSize - bSize;

    if (step > 0)
    {
        while (step > 0 && newHeadA)
        {
            newHeadA = newHeadA->next;
            --step;
        }
    }
    else
    {
        step = -step;
        while (step > 0 && newHeadB)
        {
            newHeadB = newHeadB->next;
            --step;
        }
    }

    while (newHeadA && newHeadB)
    {
        if (newHeadA != newHeadB)
        {
            newHeadA = newHeadA->next;
            newHeadB = newHeadB->next;
        }
        else
        {
            break;
        }
    }

    if (!newHeadA || !newHeadB)
    {
        return NULL;
    }

    assert(newHeadA == newHeadB);
    return newHeadA;
}
