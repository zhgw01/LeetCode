//
//  Candy.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/18/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "Candy.h"
#include <algorithm>

using namespace std;

void Candy::run()
{
    cout<<"Run Candy"<<endl;
}

void Candy::test1()
{
}


int Candy::candy(vector<int> &ratings)
{
    size_t n =ratings.size();
    
    vector<int> candies(n, 1);
    
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i-1]) {
            candies[i] = candies[i-1] + 1;
        }
    }
    
    for (int i = n -2; i >=0; --i) {
        if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) {
            candies[i] = candies[i+1] + 1;
        }
    }
    int sum = 0;
    for(auto i : candies)
        sum += i;
    
    return sum;
}