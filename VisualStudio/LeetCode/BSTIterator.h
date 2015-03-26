#pragma once
#include "stdafx.h"
#include <stack>

class LEETCODE_API BSTIterator :
    public IRun
{
public:
    BSTIterator(TreeNode *root);

    bool hasNext();

    int next();

private:
    std::stack<TreeNode*> m_nodes;
};

