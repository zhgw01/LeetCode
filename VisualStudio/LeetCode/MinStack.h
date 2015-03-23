#pragma once
#include "stdafx.h"

class LEETCODE_API MinStack :
    public IRun
{
public:
    MinStack(void);
    ~MinStack(void);

    void push(int x);

    void pop();

    int top();

    int getMin();

private:
    std::vector<int> m_min;
    std::vector<int> m_data;
};

