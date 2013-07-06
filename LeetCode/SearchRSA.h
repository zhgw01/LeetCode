//
//  SearchRSA.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/6/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__SearchRSA__
#define __LeetCode__SearchRSA__

#include "IRun.h"

class SearchRSA : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();
    void test3();
    
    int search(int A[], int n, int target);

};

#endif /* defined(__LeetCode__SearchRSA__) */
