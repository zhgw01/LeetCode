#pragma once
#include "LeetCode.h"

class LEETCODE_API IRun
{
public:
    virtual void run() {};
};

struct LEETCODE_API ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
};

struct  LEETCODE_API TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
