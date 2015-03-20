#include "stdafx.h"
#include "RotateSortArray.h"


RotateSortArray::RotateSortArray(void)
{
}


RotateSortArray::~RotateSortArray(void)
{
}

int RotateSortArray::findMin(std::vector<int> &num)
{
    assert(num.size() > 0);
    
    int l = 0, h = num.size() - 1;
    
    while (l < h && num[l] > num[h])
    {
        int m = (l+h) / 2;

        if (num[m] >= num[h])
        {
            l = m + 1;
        }
        else
        {
            h = m;
        }
    }

    return num[l];
}

int RotateSortArray::findMinWithDuplicate(std::vector<int> &num)
{
    assert(num.size() > 0);

    int l = 0, h = num.size() - 1;

    while (l < h && num[l] >= num[h])
    {
        ++l;
    }

    return num[l];
}
