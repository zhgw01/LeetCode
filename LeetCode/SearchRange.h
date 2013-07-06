//
//  SearchRange.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/6/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__SearchRange__
#define __LeetCode__SearchRange__

#include "IRun.h"

class SearchRange : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    std::vector<int> searchRange(int A[], int n, int target);

};

#endif /* defined(__LeetCode__SearchRange__) */
