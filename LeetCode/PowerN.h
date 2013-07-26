//
//  PowerN.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/26/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__PowerN__
#define __LeetCode__PowerN__

#include "IRun.h"

class PowerN : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    double pow(double x, int n);

};

#endif /* defined(__LeetCode__PowerN__) */
