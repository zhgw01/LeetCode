#include "stdafx.h"
#include "CppUnitTest.h"
#include "Fraction2Decimal.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeTest
{
    TEST_CLASS(Fraction2DecimalTest)
    {
    public:
        
        TEST_METHOD(testFraction2Decimal)
        {
            int numerator = 1;
            int denominator = 2;

            std::string expected = "0.5";

            Fraction2Decimal f;
            std::string result = f.fractionToDecimal(numerator, denominator);

            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(testFraction2DecimalInifinite)
        {
            int numerator = 1;
            int denominator = 3;

            std::string expected = "0.(3)";

            Fraction2Decimal f;
            std::string result = f.fractionToDecimal(numerator, denominator);

            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(testFraction2DecimalInifiniteBracket)
        {
            int numerator = 1;
            int denominator = 99;

            std::string expected = "0.(01)";

            Fraction2Decimal f;
            std::string result = f.fractionToDecimal(numerator, denominator);

            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(testFraction2DecimalInifiniteBracket2)
        {
            int numerator = 22;
            int denominator = 7;

            std::string expected = "3.(142857)";

            Fraction2Decimal f;
            std::string result = f.fractionToDecimal(numerator, denominator);

            Assert::IsTrue(result == expected);
        }
    };
}