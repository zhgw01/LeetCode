//
//  CombineSumUnique.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/20/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__CombineSumUnique__
#define __LeetCode__CombineSumUnique__

#include "IRun.h"

class CombineSumUnique : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
     std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target);

};

#endif /* defined(__LeetCode__CombineSumUnique__) */
