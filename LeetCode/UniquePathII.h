//
//  UniquePathII.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/29/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__UniquePathII__
#define __LeetCode__UniquePathII__

#include "IRun.h"

class UniquePathII : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    int uniquePathsWithObstacles(std::vector<std::vector<int> > &obstacleGrid);

};

#endif /* defined(__LeetCode__UniquePathII__) */
