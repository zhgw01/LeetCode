#include "stdafx.h"
#include "MajorityElement.h"


MajorityElement::MajorityElement(void)
{
}


MajorityElement::~MajorityElement(void)
{
}

int MajorityElement::majorityElement(std::vector<int> &num)
{
    if (num.empty())
    {
        return 0;
    }

    int i = 0;
    int size = num.size();
    int count = 0;
    int result;

    while(i < size)
    {
        count = 1;
        result = num[i];

        ++i;
        while (count > 0 && i < size)
        {
            if (num[i] == result)
            {
                ++count;
            }
            else
            {
                --count;
            }
            ++i;
        }

    }


    return result;
}
