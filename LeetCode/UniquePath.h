//
//  UniquePath.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/29/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__UniquePath__
#define __LeetCode__UniquePath__

#include "IRun.h"

class UniquePath : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    int uniquePaths(int m, int n);

};

#endif /* defined(__LeetCode__UniquePath__) */
