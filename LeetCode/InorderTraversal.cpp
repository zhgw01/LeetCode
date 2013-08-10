//
//  InorderTraversal.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/10/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "InorderTraversal.h"

#include <stack>

using namespace std;

void InorderTraversal::run()
{
    cout<<"Run InorderTraversal"<<endl;
    test1();
}

void InorderTraversal::test1()
{
    char a[] = "3#12";
    int na = strlen(a);
    TreeNode* root = TreeUtil::createTree(a, na);
    
    
    vector<int> result = inorderTraversalWithStack(root);
    assert(result.size() == 3);
}


vector<int> InorderTraversal::inorderTraversal(TreeNode *root)
{
    vector<int> result;
    
    if (!root) {
        return result;
    }
    
    if (root->left) {
        vector<int> left = inorderTraversal(root->left);
        result.insert(result.end(), left.begin(), left.end());
    }
    
    result.push_back(root->val);
    
    if (root->right) {
        vector<int> right = inorderTraversal(root->right);
        result.insert(result.end(), right.begin(), right.end());
    }
    
    
    return result;
}

vector<int> InorderTraversal::inorderTraversalWithStack(TreeNode *root)
{
    vector<int> result;

    stack<TreeNode *> nodes;
    TreeNode* node = root;
    while (node) {
        nodes.push(node);
        node = node->left;
    }
    
    while (!nodes.empty()) {
        
        node = nodes.top();
        result.push_back(node->val);
        nodes.pop();
        
        if (node->right) {
            
            node = node->right;
            while (node) {
                nodes.push(node);
                node = node->left;
            }
            
        }
        
    }
    
    
    
    return result;
    
}


