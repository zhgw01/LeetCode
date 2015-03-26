#pragma once
#include "stdafx.h"
class LEETCODE_API MinimumHP :
    public IRun
{
public:
    MinimumHP(void);
    ~MinimumHP(void);

    int calculateMinimumHP(std::vector<std::vector<int> > &dungeon);
};

