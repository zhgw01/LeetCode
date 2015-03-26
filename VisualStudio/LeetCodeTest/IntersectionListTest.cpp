#include "stdafx.h"
#include "CppUnitTest.h"
#include "IntersectionList.h"
#include "ListUtil.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeTest
{
    TEST_CLASS(IntersectionListTest)
    {
    public:
        
        TEST_METHOD(testIntersectionList)
        {
            int a[] = {1, 2, 3, 4, 5};
            int aSize = sizeof(a) / sizeof(*a);
            ListNode* headA = ListUtil::createList(a, aSize);

            int b[] = {11, 12};
            int bSize = sizeof(b) / sizeof(*b);
            ListNode* headB = ListUtil::createList(b, bSize);

            ListNode* expected = headA->next->next;
            headB->next->next = expected;

            IntersectionList intersection;
            ListNode* result = intersection.getIntersectionNode(headA, headB);
            
            Assert::IsTrue(result == expected);
        }

    };
}