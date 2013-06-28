//
//  ReverseKNode.h
//  LeetCode
//
//  Created by Zhang Gongwei on 6/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__ReverseKNode__
#define __LeetCode__ReverseKNode__

#include "IRun.h"
#include "NthNode.h"

class ReverseKNode : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    ListNode *reverseKGroup(ListNode *head, int k);

};


#endif /* defined(__LeetCode__ReverseKNode__) */
