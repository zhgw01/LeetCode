//
//  CopyList.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/20/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "CopyList.h"

using namespace std;

void CopyList::run()
{
    cout<<"Run CopyList"<<endl;
    test1();
}

void CopyList::test1()
{
    RandomListNode* head = new RandomListNode(-1);
    
    RandomListNode* result = copyRandomList(head);
    
    assert(result != NULL);
}


RandomListNode * CopyList::copyRandomList(RandomListNode *head)
{
    if (!head) {
        return NULL;
    }
    
    RandomListNode* current = head;
    while (current) {
        RandomListNode* node = new RandomListNode(current->label);
        node->next = current->next;
        
        current->next = node;
        current = node->next;
    }
    
    //copy random
    current = head;
    while (current) {
        RandomListNode* node = current->next;
        if (current->random) {
            node->random = current->random->next;
        }
        
        current = node->next;
    }
    
    //restore
    RandomListNode* copyHead = head->next;
    current = head;
    while (current) {
        RandomListNode* copyNode = current->next;
        RandomListNode* nextNode = copyNode->next;
        
        if (nextNode) {
            copyNode->next = nextNode->next;
        }
        
        current->next = nextNode;
        current = nextNode;
    }
    
    return copyHead;
}