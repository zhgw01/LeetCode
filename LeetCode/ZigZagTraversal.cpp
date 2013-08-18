//
//  ZigZagTraversal.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/18/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "ZigZagTraversal.h"
#include <deque>
#include <stack>

using namespace std;

void ZigZagTraversal::run()
{
    cout<<"Run ZigZagTraversal"<<endl;
    test1();
}

void ZigZagTraversal::test1()
{
    char a[] = "1";
    int na = strlen(a);
    
    TreeNode* root = TreeUtil::createTree(a, na);
    vector<vector<int> > result = zigzagLevelOrder(root);
    
    assert(result[0].size() == 1);
}


vector<vector<int> > ZigZagTraversal::zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int> > result;
    
    stack<TreeNode *> nodes;
    stack<TreeNode *> nextLevelNodes;
    if (root) {
        nodes.push(root);
        vector<int> firstRow;
        firstRow.push_back(root->val);
        result.push_back(firstRow);
    }
    
    bool leftOrder = true;
    
    while (!nodes.empty() || !nextLevelNodes.empty()) {
        vector<int> currentLevel;
        stack<TreeNode *> *currentStack = leftOrder ? &nodes : &nextLevelNodes;
        stack<TreeNode *> *nextStack = leftOrder ? &nextLevelNodes : &nodes;
        
        assert(nextStack->empty());
        
        while (!currentStack->empty()) {
            TreeNode * node = currentStack->top();
            assert(node);
            
            currentStack->pop();
            
            TreeNode *leftChild = leftOrder ? node->right : node->left;
            TreeNode *rightChild = leftOrder ? node->left : node->right;
            
            if (leftChild) {
                nextStack->push(leftChild);
                currentLevel.push_back(leftChild->val);
            }
            
            if (rightChild) {
                nextStack->push(rightChild);
                currentLevel.push_back(rightChild->val);
            }
        }
        
        if (currentLevel.size()) {
            result.push_back(currentLevel);
        }

        leftOrder = !leftOrder;
   
    }
    
    return result;
}