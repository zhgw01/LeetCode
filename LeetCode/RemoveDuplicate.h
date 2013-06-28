//
//  RemoveDuplicate.h
//  LeetCode
//
//  Created by Zhang Gongwei on 6/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__RemoveDuplicate__
#define __LeetCode__RemoveDuplicate__

#include "IRun.h"

class RemoveDuplicate : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    int removeDuplicates(int A[], int n);

};

#endif /* defined(__LeetCode__RemoveDuplicate__) */
