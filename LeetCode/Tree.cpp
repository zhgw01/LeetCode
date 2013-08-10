//
//  Tree.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/10/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "Tree.h"


TreeNode* TreeUtil::createTree(char *a, int n)
{
    if (!a || n <= 0) {
        return NULL;
    }
    
    TreeNode* root = new TreeNode(a[0] - '0');
    
    int i = 0;
    for (i = 0; i < n; ++i) {
        if (a[i] == '#') {
            break;
        }
    }
    

    TreeNode* left = createTree(a+1, i-1);
    root->left = left;
    
    if (i != n) {
        TreeNode* right = createTree(a+i+1, n-i-1);
        root->right = right;
    }
    
    
    return root;
    
}