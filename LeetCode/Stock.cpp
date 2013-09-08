//
//  Stock.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 9/8/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "Stock.h"

using namespace std;

void Stock::run()
{
    cout<<"Run Stock"<<endl;
    test1();
}

void Stock::test1()
{
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    
    int result = maxProfit(prices);
    int expected = 1;
    
    assert(result == expected);
}


int Stock::maxProfit(std::vector<int> &prices)
{
    if (prices.size() < 2) {
        return 0;
    }
    
    int profit = 0;
    
    int i = 0;
    int size = prices.size();
    
    while (i < size) {
        int min = prices[i];
        int max = min;
        ++i;
        
        while (i < size) {
            if (prices[i] >= min) {
                if (max < prices[i]) {
                    max = prices[i];
                }
                ++i;
            }
            else {
                
                if (profit < (max - min)) {
                    profit = max - min;
                }
                
                break;
            }
        }
        
        if (i == size) {
            if (profit < (max - min)) {
                profit = max - min;
            }
        }
    }
    
    return profit;
}