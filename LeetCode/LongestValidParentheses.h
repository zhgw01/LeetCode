//
//  LongestValidParentheses.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/5/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__LongestValidParentheses__
#define __LeetCode__LongestValidParentheses__

#include "IRun.h"

class LongestValidParentheses : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();
    
    int longestValidParentheses(std::string s);

};

#endif /* defined(__LeetCode__LongestValidParentheses__) */
