#pragma once
#include "IRun.h"
#include <vector>

class ListUtil
{
public:
    ListUtil(void);
    ~ListUtil(void);

    static ListNode* createList(int* a, int n);
    static std::vector<int> dumpList(const ListNode* list);

    static TreeNode* createTree(int* a, int start, int end);
    static std::vector<int> dumpTreeInOrder(const TreeNode* root);
};

