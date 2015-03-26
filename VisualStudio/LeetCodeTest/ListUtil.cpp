#include "stdafx.h"
#include "ListUtil.h"
#include <stack>

ListUtil::ListUtil(void)
{
}


ListUtil::~ListUtil(void)
{
}

ListNode* ListUtil::createList(int* a, int n)
{
    if (n == 0)
    {
        return nullptr;
    }

    ListNode* head = new ListNode(a[0]);
    ListNode* current = head;

    for (int i = 1; i < n; ++i)
    {
        ListNode* node = new ListNode(a[i]);
        current->next = node;
        current = node;
    }

    return head;
}

std::vector<int> ListUtil::dumpList(const ListNode* list)
{
    std::vector<int> result;

    const ListNode* node = list;
    while (node)
    {
        result.push_back(node->val);
        node = node->next;
    }

    return result;
}

TreeNode* ListUtil::createTree(int* a, int start, int end)
{
    if (end < start )
    {
        return nullptr;
    }
    else if (start == end)
    {
        return new TreeNode(a[start]);
    }

    int index = (start + end)/2;
    TreeNode* root = new TreeNode(a[index]);

    root->left = createTree(a, start, index - 1);
    root->right = createTree(a, index + 1, end);

    return root;
}

std::vector<int> ListUtil::dumpTreeInOrder(const TreeNode* root)
{
    std::vector<int> result;

    std::stack<const TreeNode*> nodes;
    const TreeNode* node = root;
    while (node)
    {
        nodes.push(node);
        node = node->left;
    }

    while (!nodes.empty())
    {
        node = nodes.top();
        nodes.pop();
        result.push_back(node->val);

        node = node->right;
        while (node)
        {
            nodes.push(node);
            node = node->left;
        }
    }

    return result;
}
