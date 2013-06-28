//
//  MergeKList.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 6/25/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "MergeKList.h"

using namespace std;

void MergeKList::run()
{
    cout<<"Run MergeKList" <<endl;
    
    test1();
}


ListNode* createListFromArray(int nums[], int n)
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

vector<int> getArrayFromList(ListNode *head)
{
    vector<int> result;
    
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    
    return result;
}

void MergeKList::test1()
{
    vector<ListNode *> lists;
    
    int leftArray[] = {1, 2, 2};
    int rightArray[] = { 1, 1, 2};
    
    ListNode *leftList = createListFromArray(leftArray, 3);
    ListNode *rightList = createListFromArray(rightArray, 3);
    lists.push_back(leftList);
    lists.push_back(rightList);
    
    ListNode* resultList = mergeKLists(lists);
    
    vector<int> result = getArrayFromList(resultList);
    
    assert(result.size() == 6);
}


ListNode* MergeKList::mergeKLists(std::vector<ListNode *> &lists)
{
    if (lists.size() == 0) {
        return NULL;
    }
    
    if (lists.size() == 1) {
        return lists[0];
    }
    
    ListNode* result = NULL;
    ListNode* prev = NULL;
    
    //divide the lists into half
    size_t half = lists.size() / 2;
    vector<ListNode *>::iterator half_iter = lists.begin() + half;
    std::vector<ListNode *> left(lists.begin(), half_iter);
    std::vector<ListNode *> right(half_iter, lists.end());
    
    ListNode* leftHead = mergeKLists(left);
    ListNode* rightHead = mergeKLists(right);
    
    while (leftHead && rightHead) {
        ListNode* current;
        if (leftHead->val <= rightHead->val) {
            current = leftHead;
            leftHead = leftHead->next;
        }
        else {
            current = rightHead;
            rightHead = rightHead->next;
        }
        
        current->next = NULL;
        
        if (!prev) {
            result = prev = current;
        }
        else
        {
            prev->next = current;
            prev = current;
        }
    }
    
    
    if (leftHead) {
        if (!prev) {
            result = prev = leftHead;
        }
        else
            prev->next = leftHead;
    }
    
    if (rightHead) {
        if (!prev) {
            result = prev = rightHead;
        }
        else
            prev->next = rightHead;

    }
    
    
    return result;
}