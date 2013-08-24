//
//  MinimumDepth.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "MinimumDepth.h"
#include <queue>

using namespace std;

void MinimumDepth::run()
{
    cout<<"Run MinimumDepth"<<endl;
    test1();
}

void MinimumDepth::test1()
{
    char a[] = "123#4";
    int na = strlen(a);
    
    TreeNode* root = TreeUtil::createTree(a, na);
    int result = minDepth(root);
    
    assert(result == 2);

}


int MinimumDepth::minDepth(TreeNode *root)
{

    int level = 0;
    int levelCount = 0;
    queue<TreeNode *> nodes;
    if (root) {
        nodes.push(root);
        ++levelCount;
    }
    
    while (!nodes.empty()) {
        ++level;
        
        while (levelCount-- > 0) {
            TreeNode *node = nodes.front();
            nodes.pop();
            
            if (!node->left && !node->right) {
                return level;
            }
            
            if (node->left) {
                nodes.push(node->left);
            }
            
            if (node->right) {
                nodes.push(node->right);
            }

        }
        
        levelCount = nodes.size();
    }
    
    return 0;
}