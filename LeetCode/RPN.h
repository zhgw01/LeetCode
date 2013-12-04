//
//  RPN.h
//  LeetCode
//
//  Created by Zhang Gongwei on 12/4/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__RPN__
#define __LeetCode__RPN__

#include "IRun.h"

class RPN : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    int evalRPN(std::vector<std::string> &tokens);
    bool isOperand(std::string& s);

};

#endif /* defined(__LeetCode__RPN__) */
