#include "stdafx.h"
#include "PeakNumber.h"


PeakNumber::PeakNumber(void)
{
}


PeakNumber::~PeakNumber(void)
{
}

int PeakNumber::findPeakElement(const std::vector<int> &num)
{
    if (num.empty())
    {
        return 0;
    }
    
    int max = 0;
    int size = num.size();
    int i = 1;

    while (i < size)
    {
        if (num[i] > num[max])
        {
            max = i;
        }
        ++i;
    }

    return max;
}
