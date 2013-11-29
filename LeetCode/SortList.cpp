//
//  SortList.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/29/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "SortList.h"
#include "ListNodeUtil.h"

using namespace std;

void SortList::run()
{
    cout<<"Run SortList"<<endl;
    test1();
}

void SortList::test1()
{
    std::vector<int> num = {3, 2, 4};
    ListNode* head = ListNodeUtil::createListFromVector(num);
    
    ListNode* resultHead = sortList(head);
    std::vector<int> result = ListNodeUtil::getArrayFromList(resultHead);
    assert(result.size() == 3);
}

ListNode* SortList::merge(ListNode *p, ListNode *q)
{
    ListNode *head = NULL;
    ListNode * node = NULL;
    while (p && q) {
        if (p->val <= q->val) {
            if (!node)
                head = p;
            else
                node->next = p;
            node = p;
            p = p->next;
        }
        else {
            if (!node)
                head = q;
            else
                node->next = q;
            node = q;
            q = q->next;
        }
    }
    
    if (p)
        node->next = p;
    else if (q)
        node->next = q;
    
    return head;
}

ListNode* SortList::sortList(ListNode *head)
{
    if (!head || !head->next) {
        return head;
    }
    
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = NULL;
    while (fast) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if (fast) {
            fast = fast->next;
        }
    }
    prev->next = NULL;
    
    ListNode* p = sortList(head);
    ListNode* q = sortList(slow);
    
    return merge(p, q);
}