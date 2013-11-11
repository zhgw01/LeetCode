//
//  TwoDRegion.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/11/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__TwoDRegion__
#define __LeetCode__TwoDRegion__

#include "IRun.h"

using std::vector;

class TwoDRegion : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    void solve(vector<vector<char>> &board);
    void change(vector<vector<char>> &board, int i, int j);

};

#endif /* defined(__LeetCode__TwoDRegion__) */
