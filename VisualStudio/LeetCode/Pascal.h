#pragma once

#include "stdafx.h"
#include "LeetCode.h"

#include <vector>

class LEETCODE_API Pascal :
    public IRun
{
public:
    Pascal(void);
    ~Pascal(void);

    virtual void run();

    std::vector<int> getRow(int rowIndex);
};

