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
    int aSize = getListSize(headA);
    int bSize = getListSize(headB);

    int step = aSize - bSize;
    ListNode* newHeadA = headA;
    ListNode* newHeadB = headB;

    if (step > 0)
    {
        newHeadA = advanceList(newHeadA, step);
    }
    else
    {
        newHeadB = advanceList(newHeadB, -step);
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

int IntersectionList::getListSize(ListNode* head)
{
    int size = 0;

    ListNode* node = head;
    while (node)
    {
        ++size;
        node = node->next;
    }

    return size;
}

ListNode* IntersectionList::advanceList(ListNode* head, int step)
{
    ListNode* node = head;
    while(step > 0 && node)
    {
        node = node->next;
        --step;
    }

    return node;
}
