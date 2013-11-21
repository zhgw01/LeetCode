//
//  WordBreak.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/21/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__WordBreak__
#define __LeetCode__WordBreak__

#include "IRun.h"
#include <unordered_set>

using std::string;
using std::unordered_set;

class WordBreak : public IRun
{
public:
    virtual void run();

private:
    void test1();

    bool wordBreak(string s, unordered_set<string> &dict);
};

#endif /* defined(__LeetCode__WordBreak__) */
