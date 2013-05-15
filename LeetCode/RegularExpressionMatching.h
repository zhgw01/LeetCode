//
//  RegularExpressionMatching.h
//  LeetCode
//
//  Created by Zhang Gongwei on 5/13/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__RegularExpressionMatching__
#define __LeetCode__RegularExpressionMatching__

#include "IRun.h"

class RegularExpressionMatching : public IRun {
    
public:
    virtual void run();
    
protected:
    bool isMatch(const char *s, const char *p);
    size_t minLength(const char *p);
    
    void test1();
    void test2();
    void test3();
};

#endif /* defined(__LeetCode__RegularExpressionMatching__) */
