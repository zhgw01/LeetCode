//
//  PascalTriangle.h
//  LeetCode
//
//  Created by Zhang Gongwei on 9/7/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__PascalTriangle__
#define __LeetCode__PascalTriangle__

#include "IRun.h"

using std::vector;

class PascalTriangle : public IRun
{
public:
    virtual void run();

private:
    void test1();

    vector<vector<int> > generate(int numRows);
    vector<vector<int> > generate2(int numRows);

};

#endif /* defined(__LeetCode__PascalTriangle__) */
