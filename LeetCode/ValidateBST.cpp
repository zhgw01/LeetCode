//
//  ValidateBST.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/14/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "ValidateBST.h"
#include <stack>

using namespace std;

void ValidateBST::run()
{
    cout<<"Run ValidateBST"<<endl;
    test1();
}

void ValidateBST::test1()
{
    char a[] = "11";
    int na = strlen(a);
    
    TreeNode* root = TreeUtil::createTree(a, na);
    bool result = isValidBST(root);
    
    assert(result == false);
}


bool ValidateBST::isValidBST(TreeNode* root)
{
    
    //inorder travel
    stack<TreeNode *> nodes;
    TreeNode *node = root;
    while (node) {
        nodes.push(node);
        node = node->left;
    }
    
    bool first = true;
    int lastVal = 0;
    
    while (!nodes.empty()) {
        
        node = nodes.top();
        int val = node->val;
        
        if (!first && val <= lastVal) {
            return false;
        }
        else
            first = false;
    
        lastVal = val;
        
        //find the next node
        nodes.pop();
        node = node->right;
        while (node) {
            nodes.push(node);
            node = node->left;
        }
        
    }
    
    return true;
}