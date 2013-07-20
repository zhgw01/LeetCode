//
//  CombineSum.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/19/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__CombineSum__
#define __LeetCode__CombineSum__

#include "IRun.h"

class CombineSum : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target);

};

#endif /* defined(__LeetCode__CombineSum__) */
