#pragma once
#include "irun.h"
class StlAlgorithm :
    public IRun
{
public:
    StlAlgorithm(void);
    ~StlAlgorithm(void);

    virtual void run();

private:
    void vectorDifference();
};

