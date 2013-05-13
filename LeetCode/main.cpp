//
//  main.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 4/22/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include <iostream>
#include "IRun.h"
#include "ReverseDigit.h"
#include "String2Number.h"

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Start To Run Demo!\n";
    REGISTER_CLASS(String2Number);
    DemoFactory::getInstance()->run();
    return 0;
}

