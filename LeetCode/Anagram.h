//
//  Anagram.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/26/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__Anagram__
#define __LeetCode__Anagram__

#include "IRun.h"

class Anagram : public IRun
{
public:
    virtual void run();

private:
    void test1();

    std::vector<std::string> anagrams(std::vector<std::string> &strs);
};

#endif /* defined(__LeetCode__Anagram__) */
