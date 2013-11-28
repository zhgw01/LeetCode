//
//  InsertionSort.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "InsertionSort.h"
#include "ListNodeUtil.h"

using namespace std;

void InsertionSort::run()
{
    cout<<"Run InsertionSort"<<endl;
    test1();
}

void InsertionSort::test1()
{
    std::vector<int> input = {1,1};
    ListNode* head = ListNodeUtil::createListFromVector(input);
    
    ListNode* resultHead = insertionSortList(head);
    std::vector<int> result = ListNodeUtil::getArrayFromList(resultHead);
    
    assert(result.size() == 2);
}


ListNode* InsertionSort::insertionSortList(ListNode *head)
{
    
    ListNode* result = NULL;
    ListNode* node = head;
    
    while (node) {
        //insert into the new list
        ListNode* prev = NULL;
        ListNode* next = result;
        while (next && next->val <= node->val) {
            prev = next;
            next = next->next;
        }
        
        if (prev)
            prev->next = node;
        else
            result = node;
        
        ListNode* temp = node;
        node = node->next;
        temp->next = next;
    }
    
    return result;
}