//
//  ValidParentheses.h
//  LeetCode
//
//  Created by Zhang Gongwei on 6/23/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__ValidParentheses__
#define __LeetCode__ValidParentheses__

#include "IRun.h"

class Parentheses : public IRun{
    
public:
    virtual void run();
    
private:
    void test1();
    
    bool isValid(std::string s);
};

#endif /* defined(__LeetCode__ValidParentheses__) */
