//
//  LastWorldLength.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__LastWorldLength__
#define __LeetCode__LastWorldLength__

#include "IRun.h"

class LastWorldLength : public IRun
{
public:
    virtual void run();

private:
    void test1();

    int lengthOfLastWord(const char *s);
};

#endif /* defined(__LeetCode__LastWorldLength__) */
