//
//  MaximumDepth.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/18/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "MaximumDepth.h"
#include <queue>

using namespace std;

void MaximumDepth::run()
{
    cout<<"Run MaximumDepth"<<endl;
    test1();
}

void MaximumDepth::test1()
{
    char a[] = "1#2#3#4#5";
    int na = strlen(a);
    
    TreeNode* root = TreeUtil::createTree(a, na);
    int result = maxDepth(root);
    
    assert(result == 5);

}


int MaximumDepth::maxDepth(TreeNode *root)
{
    int maxDepth = 0;
    
    
    queue<TreeNode *> nodes;
    if (root) {
        nodes.push(root);
    }
    
    while (!nodes.empty()) {
        ++maxDepth;
        size_t numLevel = nodes.size();
        size_t count = 0;
        
        while (count++ < numLevel) {
            TreeNode* nextNode = nodes.front();
            assert(nextNode);
            if (nextNode->left) {
                nodes.push(nextNode->left);
            }
            if (nextNode->right) {
                nodes.push(nextNode->right);
            }
            
            nodes.pop();
        }

    }
      
    
    return maxDepth;
    
}