// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordLadderII.h"
#include "Pascal.h"
#include "StlAlgorithm.h"
#include <memory>

int _tmain(int argc, _TCHAR* argv[])
{
    std::shared_ptr<IRun> demo = std::make_shared<StlAlgorithm>();
    demo->run();

    return 0;
}

