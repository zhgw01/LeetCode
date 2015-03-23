#pragma once
#include "stdafx.h"

class LEETCODE_API PeakNumber :
    public IRun
{
public:
    PeakNumber(void);
    ~PeakNumber(void);

    int findPeakElement(const std::vector<int> &num);
};

