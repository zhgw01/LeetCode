#include "stdafx.h"
#include "StlAlgorithm.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

StlAlgorithm::StlAlgorithm(void)
{
}


StlAlgorithm::~StlAlgorithm(void)
{
}

void StlAlgorithm::run()
{
    cout<<"Test stl algorithm"<<endl;
    vectorDifference();
}

void StlAlgorithm::vectorDifference()
{
    vector<const wchar_t *> one;
    one.push_back(L"a");
    one.push_back(L"b");
    one.push_back(L"c");

    vector<wstring> two;
    two.push_back(L"a");

    vector<const wchar_t *> result;
    set_difference(one.begin(), one.end(), two.begin(), two.end(), back_inserter(result));

    cout << result.size()<<endl;

}
