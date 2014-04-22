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
    test2();
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

void Stock::test2()
{
    vector<int> prices = {6,1,3,2,4,7};
    
    int result = maxProfit(prices);
    int expected = 6;
    
    assert(result == expected);
}

int Stock::maxProfit(std::vector<int> &prices)
{
    int result = 0;
    
    size_t minIndex = 0;
    size_t maxIndex = 0;
    
    for (size_t i = 0, iEnd = prices.size(); i < iEnd; ++i) {
        if (prices[i] < prices[minIndex]) {
            
            result = max(result, prices[maxIndex] - prices[minIndex]);
            
            minIndex = maxIndex = i;
        }
        else if(prices[i] > prices[maxIndex]) {
            maxIndex = i;
        }
    }
    
    if (maxIndex < prices.size()) {
        result = max(result, prices[maxIndex] - prices[minIndex]);
    }
    
    
    return result;
}

int Stock::maxProfit2(std::vector<int> &prices)
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