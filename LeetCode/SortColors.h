//
//  SortColors.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/3/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__SortColors__
#define __LeetCode__SortColors__

#include "IRun.h"

class SortColors : public IRun
{
public:
    virtual void run();

private:
    void test1();

    void sortColors(int A[], int n);
};

#endif /* defined(__LeetCode__SortColors__) */
