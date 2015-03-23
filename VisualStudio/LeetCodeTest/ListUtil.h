#pragma once
#include "IRun.h"
#include <vector>

class ListUtil
{
public:
    ListUtil(void);
    ~ListUtil(void);

    static ListNode* createFromArray(int* a, int n);
    static std::vector<int> dumpList(const ListNode* list);
};

