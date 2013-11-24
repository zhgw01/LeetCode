//
//  ReorderList.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__ReorderList__
#define __LeetCode__ReorderList__

#include "IRun.h"
#include "NthNode.h"

class ReorderList : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    void reorderList(ListNode *head);

};

#endif /* defined(__LeetCode__ReorderList__) */
