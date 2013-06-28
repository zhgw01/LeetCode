//
//  ReverseKNode.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 6/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "ReverseKNode.h"
#include "ListNodeUtil.h"

using namespace std;

void ReverseKNode::run()
{
    cout<<"Run ReverseKNode"<<endl;
    
    test1();
}

void ReverseKNode::test1()
{
    int num[] = {1, 2};
    ListNode* head = ListNodeUtil::createListFromArray(num, 2);
    
    int k = 2;
    ListNode* resultHead = reverseKGroup(head, k);
    
    vector<int> result = ListNodeUtil::getArrayFromList(resultHead);
    
    assert(result.size() == 2);
}


ListNode* reverseK(ListNode* head, int k)
{
    vector<ListNode *> nodes;
    ListNode* current = head;
    ListNode* result = head;
    
    for (int i = 0 ; i < k; ++i) {
        if (current) {
            nodes.push_back(current);
            current = current->next;
        }
    }
    
    if (nodes.size() == k) {
        nodes[0]->next = nodes[k - 1]->next;
        
        for (int i = k -1; i > 0; --i) {
            nodes[i]->next = nodes[i - 1];
        }
        
        result = nodes[k - 1];
    }
    
    return result;
}

ListNode* ReverseKNode::reverseKGroup(ListNode *head, int k)
{
    ListNode* result = NULL;
    ListNode* prev = NULL;
    ListNode* current = head;
    
    while (current) {
        ListNode* reverseResult = reverseK(current, k);
        if (reverseResult != current) {
            if (!result) {
                result = reverseResult;
            }
            else
                prev->next = reverseResult;
            
            prev = current;
            current = current->next;
            
            
        }
        else
            break;
    }
    
    
    return result ? result : head;
}