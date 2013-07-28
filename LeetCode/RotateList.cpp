//
//  RotateList.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "RotateList.h"
#include "ListNodeUtil.h"
#include "ArrayUtil.h"

using namespace std;

void RotateList::run()
{
    cout<<"Run RotateList"<<endl;
    test1();
}

void RotateList::test1()
{
    int num[] = {1};
    int n = sizeof(num) /sizeof(*num);
    ListNode* head = ListNodeUtil::createListFromArray(num, n);
    
    int k = 1;
    ListNode* resultHead = rotateRight(head, k);
    
    vector<int> result = ListNodeUtil::getArrayFromList(resultHead);
    
    int A[] = {1};
    int na = sizeof(A) / sizeof(*A);
    vector<int> expected = ArrayUtil::createFromArray(A, na);
    
    assert(result == expected);

}

ListNode* RotateList::rotateRight(ListNode *head, int k)
{
    if (k == 0 || !head) {
        return head;
    }
    
    ListNode* result = head;
    
    
    ListNode* slow = head;
    ListNode* fast = head;
    while (k > 0 ) {
        fast = fast->next;
        --k;
        if (!fast) {
            fast = head;
        }
    }
    
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    
    if (fast != slow) {
        result = slow->next;
        slow->next = fast->next;
        fast->next = head;
    }

   
    
    return result;
}