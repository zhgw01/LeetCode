//
//  MergeTwoSortedList.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/3/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "MergeTwoSortedList.h"
#include "ListNodeUtil.h"

using namespace std;

void MergeTwoSortedList::run()
{
    cout<<"Run MergeTwoSortedList"<<endl;
    test1();
}

void MergeTwoSortedList::test1()
{
    int a[] = {5};
    int na = sizeof(a) / sizeof(*a);
    ListNode* l1 = ListNodeUtil::createListFromArray(a, na);
    
    int b[] = {1,2, 4};
    int nb = sizeof(b) / sizeof(*b);
    ListNode* l2 = ListNodeUtil::createListFromArray(b, nb);
    

    ListNode* resultHead = mergeTwoLists(l1, l2);
    
    vector<int> result = ListNodeUtil::getArrayFromList(resultHead);
    
    assert(result.size() == 4);

}


ListNode* MergeTwoSortedList::mergeTwoLists(ListNode *l1, ListNode *l2)
{
    
    ListNode *result = NULL;
    ListNode *prev;
    
    while (l1 && l2) {
        ListNode *current;
        
        if (l1->val <= l2->val) {
            current = l1;
            l1 = l1->next;
        }
        else {
            current = l2;
            l2 = l2->next;
        }

        current->next = NULL;
        
        if (result == NULL) {
            result = current;
            prev = result;
        }
        else {
            prev->next = current;
            prev = current;
        }
    }
    
    if (l1) {
        if (result == NULL) {
            result = l1;
        }
        else
            prev->next = l1;
    }
    
    if (l2) {
        if (result == NULL) {
            result = l2;
        }
        else
            prev->next = l2;
        
    }
    
    return result;
}