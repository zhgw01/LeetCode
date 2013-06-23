//
//  NthNode.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 6/23/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "NthNode.h"


using namespace std;

void NthNode::run()
{
    cout<<"Remove Nth Node" <<endl;
}

void NthNode::test1()
{
    
}


ListNode* NthNode::removeNthFromEnd(ListNode *head, int n)
{
 
    if (n <= 0) {
        return head;
    }
    
    ListNode* result = head;
    ListNode* fast = head;
    ListNode* current = head;
    ListNode* prev = NULL;
    
    //move fast n step forward
    while (n-- > 0 && fast) {
        fast = fast->next;
    }
    
    //n is too big
    if (n > 0) {
        return result;
    }
    
    while (fast) {
        prev = current;
        current = current->next;
        fast = fast->next;
    }
    
    //we found the removed head
    if (!prev) {
        assert(current == head);
        result = head->next;
        delete current;
    }
    else
    {
        prev->next = current->next;
        delete current;
    }
    
    return result;
    
}