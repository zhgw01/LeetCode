//
//  ReverseWords.h
//  LeetCode
//
//  Created by Zhang Gongwei on 3/9/14.
//  Copyright (c) 2014 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__ReverseWords__
#define __LeetCode__ReverseWords__

#include "IRun.h"

class ReverseWords : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();
    void test3();
    
    void reverseWords(std::string& s);

};

#endif /* defined(__LeetCode__ReverseWords__) */
