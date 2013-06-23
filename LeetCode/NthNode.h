//
//  NthNode.h
//  LeetCode
//
//  Created by Zhang Gongwei on 6/23/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__NthNode__
#define __LeetCode__NthNode__

#include "IRun.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class NthNode : public IRun{
    
public:
    virtual void run();
    
private:
    ListNode *removeNthFromEnd(ListNode *head, int n);
    
    void test1();
};


#endif /* defined(__LeetCode__NthNode__) */
