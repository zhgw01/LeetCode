//
//  EditDistance.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/3/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__EditDistance__
#define __LeetCode__EditDistance__

#include "IRun.h"

class EditDistance : public IRun
{
public:
    virtual void run();

private:
    void test1();

    int minDistance(std::string word1, std::string word2);
};

#endif /* defined(__LeetCode__EditDistance__) */
