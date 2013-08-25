//
//  BTPathSum.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "BTPathSum.h"

using namespace std;

void BTPathSum::run()
{
    cout<<"Run BTPathSum"<<endl;
}

void BTPathSum::test1()
{
}


int pathSum(TreeNode* root, int &g2root)
{
    if (!root) {
        g2root = 0;
        return INT_MIN;
    }
    
    int g2left, g2right;
    int maxLeft = pathSum(root->left, g2left);
    int maxRight = pathSum(root->right, g2right);
    
    g2root = root->val + max(0, max(g2left, g2right));
    
    int maxRoot = root->val + max(0, g2left) + max(0, g2right);
    
    return max(maxRoot, max(maxLeft, maxRight));
}

int BTPathSum::maxPathSum(TreeNode *root)
{
    int g2root = 0;
    
    return pathSum(root, g2root);
}