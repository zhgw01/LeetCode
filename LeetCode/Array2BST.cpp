//
//  Array2BST.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "Array2BST.h"

using namespace std;

void Array2BST::run()
{
    cout<<"Run Array2BST"<<endl;
}

void Array2BST::test1()
{
}

TreeNode* arrayToBST(const vector<int>& num, int start, int end)
{
    if (end < start) {
        return NULL;
    }
    
    int middle = start + (end - start) / 2;
    TreeNode* root = new TreeNode(num[middle]);
    
    root->left = arrayToBST(num, start, middle - 1);
    root->right = arrayToBST(num, middle + 1, end);
    
    return root;
}

TreeNode * Array2BST::sortedArrayToBST(vector<int> &num)
{
    return arrayToBST(num, 0, num.size() - 1);
}