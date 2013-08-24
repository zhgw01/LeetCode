//
//  FlattenBST.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "FlattenBST.h"
#include <stack>

using namespace std;

void FlattenBST::run()
{
    cout<<"Run FlattenBST"<<endl;
}

void FlattenBST::test1()
{
}


void FlattenBST::flatten(TreeNode *root)
{
    if (!root) {
        return;
    }
    
    stack<TreeNode *> nodes;
    TreeNode* node = root;
    TreeNode* insertNode;
    while (node) {
        nodes.push(node);
        node = node->left;
    }
    insertNode = nodes.top();
    
    while (!nodes.empty()) {
        node = nodes.top();
        nodes.pop();
        
        if (node->right) {
            insertNode->left = node->right;
            node->right = NULL;
            node = insertNode->left;
            
            while (node) {
                nodes.push(node);
                node = node->left;
            }
            
            insertNode = nodes.top();
        }
        
    }
    
    node = root;
    while (node) {
        swap(node->left, node->right);
        node = node->right;
    }
}