//
//  WordLadder.h
//  LeetCode
//
//  Created by Zhang Gongwei on 9/15/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__WordLadder__
#define __LeetCode__WordLadder__

#include "IRun.h"
#include <unordered_set>

class WordLadder : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    int ladderLength(std::string start, std::string end, std::unordered_set<std::string> &dict);

};

#endif /* defined(__LeetCode__WordLadder__) */
