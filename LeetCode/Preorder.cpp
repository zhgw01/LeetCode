//
//  Preorder.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/25/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "Preorder.h"
#include <stack>

using namespace std;

void Preorder::run()
{
    cout<<"Run Preorder"<<endl;
    test1();
}

void Preorder::test1()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *right = new TreeNode(2);
    root->right = right;
    
    vector<int> result = preorderTraversal(root);
    assert(result.size() == 2);
}


vector<int> Preorder::preorderTraversal(TreeNode *root)
{
    vector<int> result;
    
    stack<TreeNode*> nodes;
    TreeNode* node = root;
    while (node) {
        result.push_back(node->val);
        nodes.push(node);
        node = node->left;
    }
    
    while (!nodes.empty()) {
        
        node = nodes.top();
        nodes.pop();
        
        if (node->right) {
            node = node->right;
            while (node) {
                result.push_back(node->val);
                nodes.push(node);
                node = node->left;
            }
        }
    }
    
    return result;
}
