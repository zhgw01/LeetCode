//
//  DistincSubSequence.h
//  LeetCode
//
//  Created by Zhang Gongwei on 9/2/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__DistincSubSequence__
#define __LeetCode__DistincSubSequence__

#include "IRun.h"

class DistincSubSequence : public IRun
{
public:
    virtual void run();

private:
    void test1();

    int numDistinct(std::string S, std::string T);
};

#endif /* defined(__LeetCode__DistincSubSequence__) */
