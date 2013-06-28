//
//  RemoveElement.h
//  LeetCode
//
//  Created by Zhang Gongwei on 6/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__RemoveElement__
#define __LeetCode__RemoveElement__

#include "IRun.h"

class RemoveElement : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    int removeElement(int A[], int n, int elem);

};

#endif /* defined(__LeetCode__RemoveElement__) */
