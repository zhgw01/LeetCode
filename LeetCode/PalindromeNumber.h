//
//  PalindromeNumber.h
//  LeetCode
//
//  Created by Zhang Gongwei on 5/13/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__PalindromeNumber__
#define __LeetCode__PalindromeNumber__

#include "IRun.h"

class PalindromeNumber : public IRun
{
public:
    void run();
    
protected:
    bool isPalindrome(int x);
    
};

#endif /* defined(__LeetCode__PalindromeNumber__) */
