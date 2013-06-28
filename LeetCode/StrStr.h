//
//  StrStr.h
//  LeetCode
//
//  Created by Zhang Gongwei on 6/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__StrStr__
#define __LeetCode__StrStr__

#include "IRun.h"

class StrStr : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();

    char *strStr(char *haystack, char *needle);
    char *strStr2(char *haystack, char *needle);
};

#endif /* defined(__LeetCode__StrStr__) */
