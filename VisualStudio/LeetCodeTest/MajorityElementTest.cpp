#include "stdafx.h"
#include "CppUnitTest.h"
#include "MajorityElement.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeTest
{
    TEST_CLASS(MajorityElementTest)
    {
    public:
        
        TEST_METHOD(testMajorityElement)
        {
            int a[] = {1, 2, 2, 2, 3};
            std::vector<int> num(a, a+sizeof(a)/sizeof(*a));

            int expected = 2;

            MajorityElement majority;
            int result = majority.majorityElement(num);

            Assert::IsTrue(result == expected);
        }

    };
}