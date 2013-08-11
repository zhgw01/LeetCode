//
//  BuildPreOrder.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/11/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "BuildPreOrder.h"

using namespace std;

void BuildPreOrder::run()
{
    cout<<"Run BuildPreOrder"<<endl;
    test1();
}

void BuildPreOrder::test1()
{
    vector<int> preorder(1, -1);
    vector<int> inorder(1, -1);
    
    TreeNode* result = buildTree(preorder, inorder);
    
    assert(result->val == -1);
}

TreeNode* BuildPreOrder::buildTree(std::vector<int> &preorder, std::vector<int> &inorder, int pos, int inStart, int inEnd)
{
    if (inStart > inEnd) {
        return  NULL;
    }
    
    
    int i = find(inorder.begin() + inStart, inorder.begin() + inEnd, preorder[pos]) - inorder.begin();
    
    TreeNode* root = new TreeNode(preorder[pos]);
    root->left = buildTree(preorder, inorder, pos + 1, inStart, i - 1);
    root->right = buildTree(preorder, inorder, pos + i - inStart + 1, i + 1, inEnd);
    
    return root;
}


TreeNode* BuildPreOrder::buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
{
    TreeNode* root = NULL;
    
    if (preorder.size() <=0 || preorder.size() != inorder.size()) {
        return root;
    }
    
    root = buildTree(preorder, inorder, 0, 0, inorder.size() -1 );
    
    /*
    root = new TreeNode(preorder[0]);
    
    std::vector<int>::iterator it = std::find(inorder.begin(), inorder.end(), preorder[0]);
    int leftSize = std::distance(inorder.begin(), it);
    
    if (leftSize > 0) {
        vector<int> leftPreOrder(preorder.begin() + 1, preorder.begin() + leftSize + 1);
        vector<int> leftInOrder(inorder.begin(), it);
        root->left = buildTree(leftPreOrder, leftInOrder);
    }
    
    if (leftSize + 1 < preorder.size()) {
        vector<int> rightPreOrder(preorder.begin() + leftSize + 1, preorder.end());
        vector<int> rightInOrder(it + 1, inorder.end());
        root->right = buildTree(rightPreOrder, rightInOrder);
    }
    */
    
    return root;
}


TreeNode* BuildPreOrder::buildTreeWithoutRecursive(std::vector<int> &preorder, std::vector<int> &inorder)
{
    TreeNode* root = NULL;
    
    if (preorder.size() <=0 || preorder.size() != inorder.size()) {
        return root;
    }
    

    
    
    return root;
    
    
}