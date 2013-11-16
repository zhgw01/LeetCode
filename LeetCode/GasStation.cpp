//
//  GasStation.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/16/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "GasStation.h"

using namespace std;

void GasStation::run()
{
    cout<<"Run GasStation"<<endl;
    test1();
}

void GasStation::test1()
{
    vector<int> gas = {1,2,3,4,5};
    vector<int> balance = {3,4,5,1,2};
    int result = canCompleteCircuit(gas, balance);
    assert(result == 2);
}



int GasStation::canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    size_t num = gas.size();
    int start = -1;
    int sum = 0;
    int total = 0;
    
    for (size_t i = 0; i < num; ++i) {
        sum += (gas[i] - cost[i]);
        total += (gas[i] - cost[i]);
        if (sum < 0) {
            start = i;
            sum = 0;
        }
    }
    
    return total >= 0 ? start + 1: -1;
}