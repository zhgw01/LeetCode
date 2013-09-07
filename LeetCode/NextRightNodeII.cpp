//
//  NextRightNodeII.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 9/4/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "NextRightNodeII.h"

using namespace std;

void NextRightNodeII::run()
{
    cout<<"Run NextRightNodeII"<<endl;
    test1();
}

void NextRightNodeII::test1()
{
    TreeLinkNode* root = new TreeLinkNode(0);
    connect(root);
}

TreeLinkNode* findNext(TreeLinkNode* parent)
{
    TreeLinkNode* node = parent;
    while (node) {
        if (node->left) {
            return node->left;
        }
        
        if (node->right) {
            return node->right;
        }
        
        node = node->next;
    }
    
    return NULL;
}

void NextRightNodeII::connect(TreeLinkNode *root)
{
    if (!root) {
        return;
    }
    
    TreeLinkNode* level = root;
    
    while (level) {
        TreeLinkNode* nextLevel = findNext(level);
        
        //travel on current level
        while (level) {
            
            TreeLinkNode* left = level->left;
            TreeLinkNode* right = level->right;
            
            if (left) {
                if (right)
                    left->next = right;
                else
                    left->next = findNext(level->next);
            }
            
            if(right)
                right->next = findNext(level->next);
            
            level = level->next;
        }
        
        level = nextLevel;
    }
}