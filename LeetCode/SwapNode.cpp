//
//  SwapNode.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 6/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "SwapNode.h"

using namespace std;

void SwapNode::run()
{
    cout<<"Run Swap Node" <<endl;
}

void SwapNode::test1()
{
    
}

ListNode* SwapNode::swapPairs(ListNode *head)
{
    ListNode* result = NULL;
    ListNode* current = head;
    ListNode* next;
    ListNode* prev = NULL;
    
    while (current && current->next) {
        next = current->next;
        if (!result) {
            result = next;
        }
        
        current->next = next->next;
        next->next = current;
        if (prev) {
            prev->next = next;
        }
        
        prev = current;
        current = current->next;
    }
    
    
    return result ? result : head;
}