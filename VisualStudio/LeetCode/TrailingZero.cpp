#include "stdafx.h"
#include "TrailingZero.h"


TrailingZero::TrailingZero(void)
{
}


TrailingZero::~TrailingZero(void)
{
}

int TrailingZero::trailingZeroes(int n)
{
    int result = 0;

    int count = n / 5;
    result += count;

    if (count > 0)
    {
        result += trailingZeroes(count);
    }

    return result;
}
