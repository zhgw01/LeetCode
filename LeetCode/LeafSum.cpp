//
//  LeafSum.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 9/25/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "LeafSum.h"

#include <stack>

using namespace std;

void LeafSum::run()
{
    cout<<"Run LeafSum"<<endl;
}

void LeafSum::test1()
{
}

void subTree(TreeNode* node, int& sum, int val)
{
    if (!node)
        return;
    
    if (!node->left && !node->right) {
        sum += val * 10 + node->val;
    }
    
    if (node->left) {
        subTree(node->left, sum, val * 10 + node->val);
    }
    
    if (node->right) {
        subTree(node->right, sum, val * 10 + node->val);
    }
}

int LeafSum::sumNumbers(TreeNode *root)
{
    
    int sum = 0;
    if (root)
        subTree(root, sum, 0);
    
    return sum;
}