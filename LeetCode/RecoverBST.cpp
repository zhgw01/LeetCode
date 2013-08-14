//
//  RecoverBST.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/14/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "RecoverBST.h"
#include <stack>
#include "InorderTraversal.h"

using namespace std;

void RecoverBST::run()
{
    cout<<"Run RecoverBST"<<endl;
    test1();
}

void RecoverBST::test1()
{
    char a[] = "23#1";
    int na = strlen(a);
    
    TreeNode* root = TreeUtil::createTree(a, na);
    recoverTree(root);
    
    InorderTraversal inorder;
    vector<int> result = inorder.inorderTraversal(root);
    
    assert(result[0] == 2);

}


void RecoverBST::recoverTree(TreeNode *root)
{
    TreeNode* a = NULL;
    TreeNode* b = NULL;
    
    stack<TreeNode*> nodes;
    TreeNode* node = root;
    while (node) {
        nodes.push(node);
        node = node->left;
    }
    
    TreeNode* lastNode = NULL;
    
    while (!nodes.empty()) {
        node = nodes.top();
        
        if (lastNode) {
            if (node->val < lastNode->val) {
                if (!a) {
                    a = lastNode;
                    b = node;
                }
                else {
                    b = node;
                    swap(a->val, b->val);
                    return;
                }
                    
            }
        }
        
        lastNode = node;
        nodes.pop();
        
        node = node->right;
        while (node) {
            nodes.push(node);
            node = node->left;
        }
        
    }
    
    swap(a->val, b->val);
}