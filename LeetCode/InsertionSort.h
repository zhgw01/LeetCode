//
//  InsertionSort.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__InsertionSort__
#define __LeetCode__InsertionSort__

#include "IRun.h"
#include "NthNode.h"

class InsertionSort : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    ListNode *insertionSortList(ListNode *head);

};

#endif /* defined(__LeetCode__InsertionSort__) */
