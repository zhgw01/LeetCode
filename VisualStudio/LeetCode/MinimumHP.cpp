#include "stdafx.h"
#include "MinimumHP.h"


MinimumHP::MinimumHP(void)
{
}


MinimumHP::~MinimumHP(void)
{
}

int MinimumHP::calculateMinimumHP(std::vector<std::vector<int> > &dungeon)
{
    if (dungeon.empty() || dungeon[0].empty())
    {
        return 0;
    }

    int rowSize = dungeon.size();
    int colSize = dungeon[0].size();

    std::vector<std::vector<int>> hp(rowSize, std::vector<int>(colSize, 0));
    hp[rowSize - 1][colSize - 1] = std::max(0, -dungeon[rowSize-1][colSize-1]);

    for (int i = rowSize - 2; i >= 0; --i)
    {
        hp[i][colSize - 1] = std::max(0, hp[i+1][colSize-1]-dungeon[i][colSize-1]);
    }

    for (int j = colSize -2; j >= 0; --j)
    {
        hp[rowSize-1][j] = std::max(0, hp[rowSize-1][j+1] - dungeon[rowSize-1][j]);
    }

    for (int i = rowSize - 2; i >=0; --i)
    {
        for (int j = colSize-2; j >= 0; --j)
        {
            hp[i][j] = std::max(0, std::min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j]);
        }
    }

    return hp[0][0] + 1;
}
