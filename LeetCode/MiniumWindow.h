//
//  MiniumWindow.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/4/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__MiniumWindow__
#define __LeetCode__MiniumWindow__

#include "IRun.h"

class MiniumWindow : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();

    std::string minWindow(std::string S, std::string T);
};

#endif /* defined(__LeetCode__MiniumWindow__) */
