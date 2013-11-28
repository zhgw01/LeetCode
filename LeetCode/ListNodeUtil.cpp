//
//  ListNodeUtil.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 6/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "ListNodeUtil.h"

using namespace std;


ListNode* ListNodeUtil::createListFromArray(int *nums, int n)
{
    if (n == 0) {
        return  NULL;
    }
    
    ListNode *head = new ListNode(nums[0]);
    ListNode* prev = head;
    
    for (size_t i = 1; i < n; ++i) {
        ListNode* node = new ListNode(nums[i]);
        prev->next = node;
        prev = node;
        
    }
    
    return head;

}

ListNode* ListNodeUtil::createListFromVector(std::vector<int> &v)
{
    ListNode* head = NULL;
    
    ListNode* prev = NULL;
    for(int i : v)
    {
        ListNode* node = new ListNode(i);
        if (prev)
            prev->next = node;
        else
            head = node;
        
        prev = node;
    }
    
    return head;
}

vector<int> ListNodeUtil::getArrayFromList(ListNode *head)
{
    
    vector<int> result;
    
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    
    return result;

}