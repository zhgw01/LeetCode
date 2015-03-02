#include "stdafx.h"
#include "Pascal.h"

using namespace std;

Pascal::Pascal(void)
{
}


Pascal::~Pascal(void)
{
}

void Pascal::run()
{
    cout<<"run pascal" <<endl;

    vector<int> result = getRow(3);

    for (int & i: result)
    {
        cout <<result[i] << " ";
    }
    cout<<endl;
}

std::vector<int> Pascal::getRow( int rowIndex )
{
    if (rowIndex < 0)
        return vector<int>();

    vector<int> result(rowIndex + 1, 0);
    for (int row = 0; row <= rowIndex; ++row)
    {
        result[rowIndex] = 1;

        for (int col = rowIndex - 1; col > 0; --col)
        {
            result[col] += result[col - 1];
        }

        result[0] = 1;
    }


    return result;
}
