//
//  SymmetricTree.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/15/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "SymmetricTree.h"
#include <stack>

using namespace std;

void SymmetricTree::run()
{
    cout<<"Run SymmetricTree"<<endl;
}

void SymmetricTree::test1()
{
}


bool SymmetricTree::isSymmetric(TreeNode *root)
{

    vector<int> inorder;
    
    //LvR
    stack<TreeNode *> nodes;
    TreeNode *node = root;
    while (node) {
        nodes.push(node);
        node = node->left;
    }
    
    while (!nodes.empty()) {
        node = nodes.top();
        inorder.push_back(node->val);
        nodes.pop();
        
        node = node->right;
        while (node) {
            nodes.push(node);
            node = node->left;
        }
    }
    
    //check inorder is symmetric
    size_t n = inorder.size();
    for (int i = 0; i < n / 2; ++i) {
        if (inorder[i] != inorder[n-1-i]) {
            return false;
        }
        
    }
    
    return true;
    
}