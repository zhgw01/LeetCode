//
//  String2Number.h
//  LeetCode
//
//  Created by Zhang Gongwei on 4/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__String2Number__
#define __LeetCode__String2Number__

#include "IRun.h"

class String2Number : public IRun {
public:
    virtual void run();
    
protected:
    int atoi(const char *str);
    void test1();
    void test2();
    void test3();
    void test4();
    void test5();
};

#endif /* defined(__LeetCode__String2Number__) */
