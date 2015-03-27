#pragma once
#include "stdafx.h"

class LEETCODE_API LargestNumber :
    public IRun
{
public:
    LargestNumber(void);
    ~LargestNumber(void);

     std::string largestNumber(std::vector<int> &num);
};

