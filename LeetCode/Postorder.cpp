//
//  Postorder.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/25/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "Postorder.h"
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

void Postorder::run()
{
    cout<<"Run Postorder"<<endl;
    test1();
}

void Postorder::test1()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *right = new TreeNode(2);
    root->right = right;
    
    vector<int> result = postorderTraversal(root);
    assert(result.size() == 2);
}

vector<int> Postorder::postorderTraversal(TreeNode *root)
{
    vector<int> result;
    
    stack<TreeNode*> nodes;
    if (root) {
        nodes.push(root);
    }
    
    while (!nodes.empty()) {
        TreeNode* node = nodes.top();
        result.push_back(node->val);
        nodes.pop();
        
        if (node->left) {
            nodes.push(node->left);
        }
        
        if (node->right) {
            nodes.push(node->right);
        }
    }
    
    //reverse the result
    std::reverse(result.begin(), result.end());
    
    return result;
    
}

vector<int> Postorder::postorderTraversal2(TreeNode *root)
{
    vector<int> result;
    
    TreeNode* node = root;
    stack<TreeNode *> nodes;
    unordered_map<TreeNode *, bool> visited;
    
    while (node) {
        visited[node] = false;
        nodes.push(node);
        node = node->left;
    }
    
    while (!nodes.empty()) {
        
        node = nodes.top();
        
        if (visited[node]) {
            result.push_back(node->val);
            nodes.pop();
            continue;
        }
        
        if (node->right) {
            visited[node] = true;
            node = node->right;
            while (node) {
                visited[node] = false;
                nodes.push(node);
                node = node->left;
            }
        }
        else {
            result.push_back(node->val);
            nodes.pop();
        }
        
    }
    
    
    return result;
}