//
//  StockII.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 9/14/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "StockII.h"

using namespace std;

void StockII::run()
{
    cout<<"Run StockII"<<endl;
}

void StockII::test1()
{
}


int StockII::maxProfit(std::vector<int> &prices)
{
    int sum = 0;
    
    int min = -1;
    int max = -1;
    
    for (int i = 0; i < prices.size(); ++i) {
        if (i == 0 || prices[i] < prices[i-1]) {
            sum += max - min;
            min = prices[i];
        }
        
        max = prices[i];
    }
    
    sum += max - min;
    
    return sum;
}