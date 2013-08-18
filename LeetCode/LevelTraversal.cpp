//
//  LevelTraversal.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/18/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "LevelTraversal.h"
#include <queue>

using namespace std;

void LevelTraversal::run()
{
    cout<<"Run LevelTraversal"<<endl;
}

void LevelTraversal::test1()
{
}


vector<vector<int> > LevelTraversal::levelOrder(TreeNode *root)
{
    vector<vector<int> > result;
    
    queue<TreeNode *> nodes;
    if (root) {
        nodes.push(root);
    }
  
    while (!nodes.empty()) {
        vector<int> currentLevel; //retrieve all values from current level;
        size_t numLevel = nodes.size();
        size_t count = 0;
        
        while (count++ < numLevel) {
            TreeNode* nextNode = nodes.front();
            assert(nextNode);
            currentLevel.push_back(nextNode->val);
            if (nextNode->left) {
                nodes.push(nextNode->left);
            }
            if (nextNode->right) {
                nodes.push(nextNode->right);
            }
            
            nodes.pop();
        }
        
        if (count) {
            result.push_back(currentLevel);
        }
    }
    
    
    
    return result;
}