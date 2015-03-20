#pragma once
#include "stdafx.h"

class LEETCODE_API RotateSortArray :
    public IRun
{
public:
    RotateSortArray(void);
    ~RotateSortArray(void);

    int findMin(std::vector<int> &num);
};

