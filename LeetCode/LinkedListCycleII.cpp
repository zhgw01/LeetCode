//
//  LinkedListCycleII.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/23/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//
// http://www.cnblogs.com/x1957/p/3406448.html
//

#include "LinkedListCycleII.h"

using namespace std;

void LinkedListCycleII::run()
{
    cout<<"Run LinkedListCycleII"<<endl;
}

void LinkedListCycleII::test1()
{
}


ListNode *LinkedListCycleII::detectCycle(ListNode *head)
{
    if (!head) {
        return NULL;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (slow && fast) {
        slow = slow->next;
        if (fast->next)
            fast = fast->next->next;
        else
            return NULL;
        
        if (!slow || !fast) {
            return NULL;
        }
        
        if (slow == fast) {
            break;
        }
    }
    
    ListNode* result = head;
    while (result != slow ) {
        result = result->next;
        slow = slow->next;
    }
    
    return result;
    
}