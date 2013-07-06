//
//  SearchInsertPosition.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/6/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__SearchInsertPosition__
#define __LeetCode__SearchInsertPosition__

#include "IRun.h"

class SearchInsertPosition : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    int searchInsert(int A[], int n, int target);

};

#endif /* defined(__LeetCode__SearchInsertPosition__) */
