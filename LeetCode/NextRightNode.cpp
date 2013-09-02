//
//  NextRightNode.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 9/2/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "NextRightNode.h"
#include <queue>

using namespace std;

void NextRightNode::run()
{
    cout<<"Run NextRightNode"<<endl;
}

void NextRightNode::test1()
{
}


void NextRightNode::connect(TreeLinkNode *root)
{
    if (!root || !root->left || !root->right) {
        return;
    }
    
    TreeLinkNode* level = root;
    
    while (level && level->left && level->right) {
        
        TreeLinkNode* node = level;
        
        //trvel on current level
        while (node) {
            node->left->next = node->right;
            if (node->next) {
                node->right->next = node->next->left;
            }
            
            node = node->next;
        }
        
        
        //start next level
        level = level->left;
    }
}