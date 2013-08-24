//
//  SortedList2BST.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__SortedList2BST__
#define __LeetCode__SortedList2BST__

#include "IRun.h"
#include "Tree.h"
#include "NthNode.h"

class SortedList2BST : public IRun
{
public:
    virtual void run();

private:
    void test1();

    TreeNode *sortedListToBST(ListNode *head);
};

#endif /* defined(__LeetCode__SortedList2BST__) */
