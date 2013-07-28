//
//  KPermutation.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__KPermutation__
#define __LeetCode__KPermutation__

#include "IRun.h"

class KPermutation : public IRun
{
public:
    virtual void run();

private:
    void test1();

    std::string getPermutation(int n, int k);
};

#endif /* defined(__LeetCode__KPermutation__) */
