//
//  ConCatWords.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/2/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__ConCatWords__
#define __LeetCode__ConCatWords__

#include "IRun.h"

class ConCatWords : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();

    std::vector<int> findSubstring(std::string S, std::vector<std::string> &L);
};

#endif /* defined(__LeetCode__ConCatWords__) */
