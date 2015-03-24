#include "stdafx.h"
#include "MaximumGap.h"
#include <algorithm>

//////////////////////////////////////////////////////////////////////////
// algorithm: http://cgm.cs.mcgill.ca/~godfried/teaching/dm-reading-assignments/Maximum-Gap-Problem.pdf
//////////////////////////////////////////////////////////////////////////

MaximumGap::MaximumGap(void)
{
}


MaximumGap::~MaximumGap(void)
{
}

int MaximumGap::maximumGap(std::vector<int> &num)
{
    if (num.size() < 2)
    {
        return 0;
    }

    auto minmaxIterator = std::minmax_element(num.begin(), num.end());
    int min = *(minmaxIterator.first);
    int max = *(minmaxIterator.second);

    int bucketNumber = num.size() - 1;
    int delta = (max - min + bucketNumber - 1) / bucketNumber;
    std::vector<std::vector<int>> buckets(num.size());

    for (int x: num)
    {
        int index = (x - min)/delta;
        if (buckets[index].empty())
        {
            //bk-min, bk-max
            buckets[index].push_back(x);
            buckets[index].push_back(x);
        }
        else
        {
            if (x < buckets[index][0])
            {
                buckets[index][0] = x;
            }
            else if (x > buckets[index][1])
            {
                buckets[index][1] = x;
            }
        }

    }

    //according to pigeonhole principle, at least on bucket is empty (assert i), then the executive number 
    // fall in bucket[i-1], bucket[i+1] has gap more than delta, bk-max - bk-min < bucket, so the maximum gap
    // should be found between buckets
    if (buckets.size() == 1)
    {
        return buckets[0][1] - buckets[0][0];
    }

    int gap = 0;
    int prev = -1;
    for (int i = 0, iEnd = buckets.size(); i < iEnd; ++i)
    {
        if (buckets[i].empty())
        {
            continue;
        }
        if (prev != -1)
        {
            gap = std::max(gap, buckets[i][0]-buckets[prev][1]);
        }
        prev = i;
    }

    return gap;
}
