//
//  SortedList2BST.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "SortedList2BST.h"

using namespace std;

void SortedList2BST::run()
{
    cout<<"Run SortedList2BST"<<endl;
}

void SortedList2BST::test1()
{
}

TreeNode* list2BST(ListNode* &list, int start, int end)
{
    if (start > end) {
        return NULL;
    }
    
    int middle = start + (end - start) / 2;
    
    TreeNode* root = new TreeNode(0);
    root->left = list2BST(list, start, middle -1);
    root->val = list->val;
    list = list->next;
    root->right = list2BST(list, middle + 1, end);
    
    return root;
    
}

TreeNode* SortedList2BST::sortedListToBST(ListNode *head)
{
    int size = 0;
    
    ListNode* node = head;
    while (node) {
        ++size;
        node = node->next;
    }
    
    return list2BST(head, 0, size - 1);
    
}