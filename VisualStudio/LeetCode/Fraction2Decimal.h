#pragma once
#include "stdafx.h"

class LEETCODE_API Fraction2Decimal :
    public IRun
{
public:
    Fraction2Decimal(void);
    ~Fraction2Decimal(void);

    std::string fractionToDecimal(int numerator, int denominator);
};

