//
//  PathSum.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/25/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "PathSum.h"
#include <stack>

using namespace std;

void PathSum::run()
{
    cout<<"Run PathSum"<<endl;
}

void PathSum::test1()
{
}


bool PathSum::hasPathSum(TreeNode *root, int sum)
{
    
    if (!root) {
        return false;
    }
    
    sum -= root->val;
    
    if (!root->left && !root->right && !sum) {
        return true;
    }
    
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    
}