//
//  4Sum.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 6/21/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "4Sum.h"


using namespace std;

void FourSum::run()
{
    cout<<"Run 4Sum"<<endl;
    
    test3();
}

void FourSum::test1()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(0);
    num.push_back(-1);
    num.push_back(0);
    num.push_back(-2);
    num.push_back(2);
    
    int target = 0;
    vector<vector<int> > result = fourSum(num, target);
    assert(result.size() == 3);
}


void FourSum::test2()
{
    vector<int> num;
    
    int target = 0;
    vector<vector<int> > result = fourSum(num, target);
    assert(result.size() == 0);
}

void FourSum::test3()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(-2);
    num.push_back(-5);
    num.push_back(-4);
    num.push_back(-3);
    num.push_back(3);
    num.push_back(3);
    num.push_back(5);
    
    
    int target = -11;
    vector<vector<int> > result = fourSum(num, target);
    assert(result.size() == 1);

}


vector<vector<int> > FourSum::fourSum(std::vector<int> &num, int target)
{
    typedef vector<int> quadruplet;
    vector<quadruplet> result;
    
    sort(num.begin(), num.end());
    
    size_t n_size = num.size();
    
    for (size_t i = 0; i + 3 < n_size ; ++i) {
        if (i != 0 && num[i] == num[i - 1]) {
            continue;
        }
        int i_remain = target - num[i];
              
        for (size_t j = i + 1; j + 2 < n_size ; ++j) {
            if (j != i + 1  && num[j] == num[j - 1]) {
                continue;
            }
            int j_remain = i_remain - num[j];
                      
            for (size_t k = j + 1; k + 1 < n_size; ++k) {
                if (k != j + 1 && num[k] == num[k - 1]) {
                    continue;
                }
                int k_remain = j_remain - num[k];
                if (binary_search(num.begin() + (k + 1), num.end(), k_remain)) {
                    quadruplet q;
                    q.push_back(num[i]);
                    q.push_back(num[j]);
                    q.push_back(num[k]);
                    q.push_back(k_remain);
                    
                    
                    result.push_back(q);
                }
            }
        }
        
    }
    
    return result;
}