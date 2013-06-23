//
//  GenerateParentheses.h
//  LeetCode
//
//  Created by Zhang Gongwei on 6/23/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__GenerateParentheses__
#define __LeetCode__GenerateParentheses__

#include "IRun.h"

class GenerateParentheses : public IRun{
public:
    virtual void run();
    
private:
    void test1();
    void test2();
    
    std::vector<std::string> generateParenthesis(int n);
    
};


#endif /* defined(__LeetCode__GenerateParentheses__) */
