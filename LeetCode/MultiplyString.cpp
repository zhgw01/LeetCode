//
//  MultiplyString.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/20/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "MultiplyString.h"
#include <sstream>

using namespace std;

void MultiplyString::run()
{
    cout<<"Run MultiplyString"<<endl;
    
    test2();
}

void MultiplyString::test1()
{
    string num1 = "9";
    string num2 = "9";
    
    string result = multiply(num1, num2);
    string expected = "81";
    
    assert(result == expected);
}

void MultiplyString::test2()
{
    string num1 = "123";
    string num2 = "456";
    
    string result = multiply(num1, num2);
    string expected = "56088";
    
    assert(result == expected);

}

string MultiplyString::multiply(std::string num1, std::string num2)
{
    string result;
    
    if (num1.empty() || num2.empty()) {
        return result;
    }
    
    if ((num1.size() == 1 && num1[0] == '0') ||
        (num2.size() == 1 && num2[0] == '0')
        )
    {
        return "0";
    }
    
    int carry = 0;
    for (int i = static_cast<int>(num1.size()) - 1; i >= 0; --i) {
        
        if (num1[i] == '0') {
            result.insert(result.begin(), '0');
            continue;
        }
        
        int shift = static_cast<int>(num1.size()) - i - 1;

        
        for (int j = static_cast<int>(num2.size()) - 1; j >= 0; --j) {
            
            int digitIndex = static_cast<int>(num2.size()) - j - 1 + shift;
            int index = -1;
            
            if (result.size() > digitIndex) {
                index = static_cast<int>(result.size()) - 1 - digitIndex;
                carry += result[index] - '0';
            }
            
            int mult = (num1[i] - '0') * (num2[j] - '0') + carry;
            
            carry = mult / 10;
            char current = '0' + mult % 10;
            
            if (index != -1) {
                result[index] = current;
            }
            else
                result.insert(result.begin(), current);
        }

        if (carry > 0) {
            result.insert(result.begin(), '0' + carry);
            carry = 0;
        }
        


    }
    
    
    return result;
}