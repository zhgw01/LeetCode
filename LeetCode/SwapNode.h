//
//  SwapNode.h
//  LeetCode
//
//  Created by Zhang Gongwei on 6/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__SwapNode__
#define __LeetCode__SwapNode__

#include "IRun.h"
#include "NthNode.h"

class SwapNode : public IRun{
public:
    virtual void run();
    
private:
    void test1();
    
    ListNode *swapPairs(ListNode *head);
};


#endif /* defined(__LeetCode__SwapNode__) */
