//
//  RotateList.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__RotateList__
#define __LeetCode__RotateList__

#include "IRun.h"
#include "NthNode.h"

class RotateList : public IRun
{
public:
    virtual void run();

private:
    void test1();

    ListNode *rotateRight(ListNode *head, int k);
};

#endif /* defined(__LeetCode__RotateList__) */
