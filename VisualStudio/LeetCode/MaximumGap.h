#pragma once
#include "stdafx.h"

class LEETCODE_API MaximumGap :
    public IRun
{
public:
    MaximumGap(void);
    ~MaximumGap(void);

    int maximumGap(std::vector<int> &num);
};

