//
//  Permutation.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__Permutation__
#define __LeetCode__Permutation__

#include "IRun.h"

class Permutation : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    std::vector<std::vector<int> > permute(std::vector<int> &num);

};

#endif /* defined(__LeetCode__Permutation__) */
