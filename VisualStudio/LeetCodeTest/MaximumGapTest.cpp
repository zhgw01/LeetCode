#include "stdafx.h"
#include "CppUnitTest.h"
#include "MaximumGap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeTest
{
    TEST_CLASS(MaximumGapTest)
    {
    public:
        
        TEST_METHOD(testMaximumGap)
        {
            int a[] = {12,2,3};
            std::vector<int> num(a, a + sizeof(a) / sizeof(*a));
            int expected = 9;

            MaximumGap gap;
            int result = gap.maximumGap(num);

            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(testMaximumGap2)
        {
            int a[] = {3,6,9,1};
            std::vector<int> num(a, a + sizeof(a) / sizeof(*a));
            int expected = 3;

            MaximumGap gap;
            int result = gap.maximumGap(num);

            Assert::IsTrue(result == expected);
        }

    };
}