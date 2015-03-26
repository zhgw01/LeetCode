#include "stdafx.h"
#include "BSTIterator.h"



BSTIterator::BSTIterator(TreeNode *root)
{
    TreeNode* node = root;
    while (node)
    {
        m_nodes.push(node);
        node = node->left;
    }
}

bool BSTIterator::hasNext()
{
    return !m_nodes.empty();
}

int BSTIterator::next()
{
    int result;
    TreeNode* node = m_nodes.top();
    m_nodes.pop();

    result = node->val;
    node = node->right;
    while (node)
    {
        m_nodes.push(node);
        node = node->left;
    }

    return result;
}
