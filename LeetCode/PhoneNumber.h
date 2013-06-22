//
//  PhoneNumber.h
//  LeetCode
//
//  Created by Zhang Gongwei on 6/22/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__PhoneNumber__
#define __LeetCode__PhoneNumber__

#include "IRun.h"

class PhoneNumber : public IRun
{
public:
    virtual void run();
    
private:
    std::vector<std::string> letterCombinations(const std::string& digits);
    
    void test1();
    void test2();
    
};


#endif /* defined(__LeetCode__PhoneNumber__) */
