//
//  BalancedTree.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "BalancedTree.h"

using namespace std;

void BalancedTree::run()
{
    cout<<"Run BalancedTree"<<endl;
}

void BalancedTree::test1()
{
}

bool treeHeight(TreeNode* root, int& height)
{
    if (!root) {
        height = 0;
        return true;
    }
    
    int leftHeight = 0;
    int rightHeight = 0;
    
    if (treeHeight(root->left, leftHeight) &&
        treeHeight(root->right, rightHeight)
        )
    {
        if (abs(rightHeight - leftHeight) <= 1) {
            height = max(leftHeight, rightHeight) + 1;
            return true;
        }
        
    }
    
    return false;
}



bool BalancedTree::isBalanced(TreeNode *root)
{
    int height = 0;
    return treeHeight(root, height);
    
}