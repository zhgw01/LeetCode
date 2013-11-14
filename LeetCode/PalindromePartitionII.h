//
//  PalindromePartitionII.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/13/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__PalindromePartitionII__
#define __LeetCode__PalindromePartitionII__

#include "IRun.h"

class PalindromePartitionII : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();
    
    int minCut(std::string s);

};

#endif /* defined(__LeetCode__PalindromePartitionII__) */
