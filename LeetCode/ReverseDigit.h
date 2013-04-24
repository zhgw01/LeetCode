//
//  ReverseDigit.h
//  LeetCode
//
//  Created by Zhang Gongwei on 4/22/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__ReverseDigit__
#define __LeetCode__ReverseDigit__

#include "IRun.h"

class ReverseDigit : public IRun
{
public:
    void run();
    
protected:
    int reverse(int x);
};

#endif /* defined(__LeetCode__ReverseDigit__) */
