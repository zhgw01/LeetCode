//
//  MultipleNumber.h
//  LeetCode
//
//  Created by Zhang Gongwei on 9/24/14.
//  Copyright (c) 2014 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__MultipleNumber__
#define __LeetCode__MultipleNumber__

#include "IRun.h"

class MultipleNumber : public IRun
{
public:
    virtual void run();
    
protected:
    std::vector<int> nonUnique(std::vector<int>& number);

private:
    void test1();

};

#endif /* defined(__LeetCode__MultipleNumber__) */
