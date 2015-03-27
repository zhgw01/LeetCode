#include "stdafx.h"
#include "CppUnitTest.h"
#include "LargestNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeTest
{
    TEST_CLASS(LargestNumberTest)
    {
    public:
        
        TEST_METHOD(testLargestNumber)
        {
            int a[] = {3, 30, 34, 5, 9};
            std::vector<int> num(a, a + sizeof(a)/sizeof(*a));

            std::string expected = "9534330";

            LargestNumber l;
            std::string result = l.largestNumber(num);

            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(testLargestNumberWithPrefixZero)
        {
            int a[] = {0,0};
            std::vector<int> num(a, a + sizeof(a)/sizeof(*a));

            std::string expected = "0";

            LargestNumber l;
            std::string result = l.largestNumber(num);

            Assert::IsTrue(result == expected);
        }

    };
}