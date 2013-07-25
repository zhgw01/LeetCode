//
//  RotateImage.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/25/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__RotateImage__
#define __LeetCode__RotateImage__

#include "IRun.h"

class RotateImage : public IRun
{
public:
    virtual void run();

private:
    void test1();

    void rotate(std::vector<std::vector<int> > &matrix);
};

#endif /* defined(__LeetCode__RotateImage__) */
