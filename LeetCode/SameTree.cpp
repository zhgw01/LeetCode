//
//  SameTree.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/15/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "SameTree.h"

using namespace std;

void SameTree::run()
{
    cout<<"Run SameTree"<<endl;
}

void SameTree::test1()
{
    
}


bool SameTree::isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p || !q) {
        return p == q;
    }
    
    if (p->val == q->val) {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    else
        return false;
}