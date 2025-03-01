#include "bits/stdc++.h"
using namespace std;

void InsertTickElem(vector<int>& _InTicks, int _InOffsetIdx, int _InMajorTickLen)
{
    /*
    4 1 2 1 3 1 2 1 4
    */
    const int&& RightOffsetIdx = _InOffsetIdx + pow(2, _InMajorTickLen - 1);

    if (_InTicks[_InOffsetIdx] < 1) _InTicks[_InOffsetIdx] = _InMajorTickLen;
    if (_InTicks[RightOffsetIdx] < 1) _InTicks[RightOffsetIdx] = _InMajorTickLen;

    if (_InMajorTickLen < 2) return;
    
    InsertTickElem(_InTicks, _InOffsetIdx, _InMajorTickLen - 1);
    InsertTickElem(_InTicks, _InOffsetIdx + RightOffsetIdx / 2, _InMajorTickLen - 1);
}

void EnglishRuler(int _InMajorTickLen)
{
    const int&& TicksSize = pow(2, _InMajorTickLen - 1) + 1;
    vector<int> Ticks(TicksSize, 0);

    InsertTickElem(Ticks, 0, _InMajorTickLen);
    
    for (auto& elem : Ticks)
    {
        cout << elem << endl;
    }

#if 0
    for (int i = 0; i < TicksSize; i++)
    {
        for (int i = 0; i < Ticks[i]; i++)
        {
            cout << '-';
        }

        cout << '\n' << endl;
    }
#endif
}

int main()
{
    int nInput;
    cin >> nInput;
    
    EnglishRuler(nInput);
}
