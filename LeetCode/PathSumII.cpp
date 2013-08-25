//
//  PathSumII.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/25/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "PathSumII.h"
#include <stack>

using namespace std;

void PathSumII::run()
{
    cout<<"Run PathSumII"<<endl;
    
    test1();
}

void PathSumII::test1()
{
    char a[] = "12";
    int na = strlen(a);
    
    TreeNode* root = TreeUtil::createTree(a, na);
    vector<vector<int> > result = pathSum(root, 0);
    
    assert(result.size() == 0);

   
}


vector<vector<int> > PathSumII::pathSum(TreeNode *root, int sum)
{
    vector<vector<int> > result;
    
    if (!root) {
        return result;
    }
    
    struct Item {
        TreeNode *node;
        bool visited;
        
        Item(TreeNode * n): node(n), visited(false) {}
    };
    
    stack<Item> nodes;
    TreeNode *node = root;
    int currentSum = 0;
    vector<int> path;
    while (node) {
        path.push_back(node->val);
        currentSum += node->val;
        nodes.push(Item(node));
        node = node->left;
    }
    
    while (!nodes.empty()) {
        Item& item= nodes.top();
        
        if (!item.node->left && !item.node->right) {
            if (currentSum == sum) {
                result.push_back(path);
            }
            
            path.pop_back();
            currentSum -= item.node->val;
            nodes.pop();
        }
        else if (item.node->right && !item.visited) {

                item.visited = true;
                node = item.node->right;
                
                while (node) {
                    path.push_back(node->val);
                    currentSum += node->val;
                    nodes.push(Item(node));
                    node = node->left;
                }

        }
        else {
            path.pop_back();
            currentSum -= item.node->val;
            nodes.pop();
        }
        
    }
    
    return result;
}