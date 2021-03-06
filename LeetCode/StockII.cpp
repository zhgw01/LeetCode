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
    int result = 0;
    
    size_t buyIndex = 0;
    size_t totalNumber = prices.size();
    
    while (buyIndex + 1 < totalNumber) {
        if (prices[buyIndex + 1] > prices[buyIndex]) {
            result += prices[buyIndex + 1] - prices[buyIndex];
        }
        
        ++buyIndex;
    }
    
    
    return result;
    
}


int StockII::maxProfit2(std::vector<int> &prices)
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