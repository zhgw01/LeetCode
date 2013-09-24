//
//  LongestConsecutiveSequence.h
//  LeetCode
//
//  Created by Zhang Gongwei on 9/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__LongestConsecutiveSequence__
#define __LeetCode__LongestConsecutiveSequence__

#include "IRun.h"

class LongestConsecutiveSequence : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();
    
    int longestConsecutive(std::vector<int> &num);

};

#endif /* defined(__LeetCode__LongestConsecutiveSequence__) */
