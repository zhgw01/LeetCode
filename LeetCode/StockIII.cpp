//
//  StockIII.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 9/14/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "StockIII.h"

using namespace std;

void StockIII::run()
{
    cout<<"Run StockIII"<<endl;
    test2();
}

void StockIII::test1()
{
    vector<int> prices;
    prices.push_back(4);
    prices.push_back(1);
    prices.push_back(2);
    
    int result = maxProfit(prices);
    int expect = 1;
    
    assert(result == expect);
}

void StockIII::test2()
{
    vector<int> prices;
    prices.push_back(2);
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(0);
    prices.push_back(1);
    
    int result = maxProfit(prices);
    int expect = 2;
    
    assert(result == expect);
}

int StockIII::maxProfit(std::vector<int> &prices)
{
    size_t num = prices.size();
    
    std::vector<int> historyProfit(num, 0);
    std::vector<int> futureProfit(num, 0);
    
    size_t minIndex = 0;
    for (size_t i = 0; i < num; ++i) {
        if (prices[i] < prices[minIndex]) {
            minIndex = i;
        }
        
        historyProfit[i] = prices[i] - prices[minIndex];
    }
    
    size_t maxIndex = num - 1;
    for (int i = static_cast<int>(num - 2); i >= 0; --i) {
   
        if (prices[maxIndex] < prices[i]) {
            maxIndex = i;
        }
        
        futureProfit[i] = max(futureProfit[i+1], prices[maxIndex] - prices[i]);
    }
    
    int result = 0;
    for (size_t i = 0; i < num; ++i) {
        result = max(result, historyProfit[i] + futureProfit[i]);
    }

    return result;
}

int StockIII::maxProfit2(std::vector<int> &prices)
{
    
    if (prices.size() < 1) {
        return 0;
    }
    
    size_t num = prices.size();
    
    vector<int> historyProfit(num, 0);
    vector<int> futureProfit(num, 0);
    
    //calculate history profit
    int min = prices[0];
    int max = min;
    
    for (int i = 1; i < num; ++i) {
        
        if (prices[i] < min) {
            historyProfit[i] = max - min;
            max = min = prices[i];
            continue;
        }
        
        if (prices[i] > max) {
            max = prices[i];
        }
        historyProfit[i] = max - min;
    }
    
    //calculate future profit
    futureProfit[num -1] = 0;
    max = min = prices[num-1];
    
    int maxProfit = historyProfit[num-1] + futureProfit[num-1];
    
    for (int i = num - 2; i >=0; --i) {
        if (prices[i] > max) {
            min = max = prices[i];
        }
        else if(prices[i] < min) {
            min = prices[i];
        }
        
        
        futureProfit[i] = futureProfit[i+1];
        if (max - min > futureProfit[i]) {
            futureProfit[i] = max - min;
        }
        
        if (historyProfit[i] + futureProfit[i] > maxProfit) {
            maxProfit = historyProfit[i] + futureProfit[i];
        }
    }
    
    return maxProfit;
}