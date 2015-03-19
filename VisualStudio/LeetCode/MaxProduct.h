#pragma once
#include "irun.h"
class LEETCODE_API MaxProduct :
    public IRun
{
public:
    MaxProduct(void);
    ~MaxProduct(void);

    virtual void run() {}

    int maxProduct(int A[], int n);
};

