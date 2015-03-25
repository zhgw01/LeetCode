#include "stdafx.h"
#include "Fraction2Decimal.h"
#include <string>
#include <unordered_map>


Fraction2Decimal::Fraction2Decimal(void)
{
}


Fraction2Decimal::~Fraction2Decimal(void)
{
}

std::string Fraction2Decimal::fractionToDecimal(int numerator, int denominator)
{
    std::string result = "";

    if ((numerator < 0) ^ (denominator < 0) && numerator != 0)
    {
        result += "-";
    }

    long long n = numerator, d = denominator;
    n = abs(n);
    d = abs(d);

    
    long long r = n % d;
    std::unordered_map<int, int> remainingsMap;

    result += std::to_string(n/d);
    if (r != 0 && r < d)
    {
        result += ".";
    }

    
    while(r != 0)
    {
        if (remainingsMap.find(r) != remainingsMap.end())
        {
            result.insert(remainingsMap[r], "(");
            result += ")";
            
            break;
        }
        else
        {
            remainingsMap[r] = result.size();
        }

        r = r * 10;
        result += std::to_string(r/d);
        r = r % d;
    } 


    return result;
}
