//
//  NextPermutation.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/3/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__NextPermutation__
#define __LeetCode__NextPermutation__

#include "IRun.h"

class NextPermutation : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    void nextPermutation(std::vector<int> &num);

};

#endif /* defined(__LeetCode__NextPermutation__) */
