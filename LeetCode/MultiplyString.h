//
//  MultiplyString.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/20/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__MultiplyString__
#define __LeetCode__MultiplyString__

#include "IRun.h"


class MultiplyString : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();

    std::string multiply(std::string num1, std::string num2);
};

#endif /* defined(__LeetCode__MultiplyString__) */
