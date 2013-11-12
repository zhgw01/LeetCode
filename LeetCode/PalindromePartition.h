//
//  PalindromePartition.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/12/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__PalindromePartition__
#define __LeetCode__PalindromePartition__

#include "IRun.h"

using std::vector;
using std::string;

class PalindromePartition : public IRun
{
public:
    virtual void run();

private:
    void test1();

    vector<vector<string>> partition(string s);
    bool isPalindrome(const string& s);
};

#endif /* defined(__LeetCode__PalindromePartition__) */
