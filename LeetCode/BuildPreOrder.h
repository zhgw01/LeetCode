//
//  BuildPreOrder.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/11/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__BuildPreOrder__
#define __LeetCode__BuildPreOrder__

#include "IRun.h"
#include "Tree.h"

class BuildPreOrder : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder);
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder, int pos, int inStart, int inEnd);
    TreeNode *buildTreeWithoutRecursive(std::vector<int> &preorder, std::vector<int> &inorder);

};

#endif /* defined(__LeetCode__BuildPreOrder__) */
