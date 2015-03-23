#include "stdafx.h"
#include "ListUtil.h"


ListUtil::ListUtil(void)
{
}


ListUtil::~ListUtil(void)
{
}

ListNode* ListUtil::createFromArray(int* a, int n)
{
    if (n == 0)
    {
        return nullptr;
    }

    ListNode* head = new ListNode(a[0]);
    ListNode* current = head;

    for (int i = 1; i < n; ++i)
    {
        ListNode* node = new ListNode(a[i]);
        current->next = node;
        current = node;
    }

    return head;
}

std::vector<int> ListUtil::dumpList(const ListNode* list)
{
    std::vector<int> result;

    const ListNode* node = list;
    while (node)
    {
        result.push_back(node->val);
        node = node->next;
    }

    return result;
}
