#pragma once
#include "stdafx.h"

class LEETCODE_API TrailingZero :
    public IRun
{
public:
    TrailingZero(void);
    ~TrailingZero(void);

    int trailingZeroes(int n);
};

