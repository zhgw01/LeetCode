#pragma once
#include "stdafx.h"

class LEETCODE_API MajorityElement :
    public IRun
{
public:
    MajorityElement(void);
    ~MajorityElement(void);

    int majorityElement(std::vector<int> &num);
};

