//
//  WildCardMatch.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/21/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__WildCardMatch__
#define __LeetCode__WildCardMatch__

#include "IRun.h"

class WildCardMatch : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();
    void test3();

    bool isMatch(const char *s, const char *p);
};

#endif /* defined(__LeetCode__WildCardMatch__) */
