//
//  ReorderList.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "ReorderList.h"
#include "ListNodeUtil.h"

using namespace std;

void ReorderList::run()
{
    cout<<"Run ReorderList"<<endl;
    test1();
}

void ReorderList::test1()
{
    int num[3] = {1, 2, 3};
    int n = sizeof(num) / sizeof(*num);
    
    ListNode* head = ListNodeUtil::createListFromArray(num, n);
    reorderList(head);
    
    vector<int> result = ListNodeUtil::getArrayFromList(head);
    assert(result.size() == 3);
    
}


void ReorderList::reorderList(ListNode *head)
{
    if (!head) {
        return;
    }
    
    //split the linked list into two list
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode*  firstTail= NULL;
    while (fast) {
        fast = fast->next;
        if (fast) {
            fast = fast->next;
        }
        
        firstTail = slow;
        slow = slow->next;
    }
    if (firstTail) {
        firstTail->next = NULL;
    }
    
    
    //reverse the second half list
    ListNode* prev = NULL;
    while (slow) {
        ListNode* next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }
    ListNode* secondHead = prev ? prev : slow;
    
    //merge into single list
    ListNode* first = head;
    ListNode* second = secondHead;
    
    while (first && second) {
        ListNode* firstNext = first->next;
        ListNode* secondNext = second->next;
        
        first->next = second;
        second->next = firstNext;
        
        first = firstNext;
        second = secondNext;
    }
    
}