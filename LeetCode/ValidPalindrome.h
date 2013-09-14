//
//  ValidPalindrome.h
//  LeetCode
//
//  Created by Zhang Gongwei on 9/14/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__ValidPalindrome__
#define __LeetCode__ValidPalindrome__

#include "IRun.h"

class ValidPalindrome : public IRun
{
public:
    virtual void run();

private:
    void test1();

    bool isPalindrome(std::string s);
};

#endif /* defined(__LeetCode__ValidPalindrome__) */
