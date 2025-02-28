#include "bits/stdc++.h"
using namespace std;

void InsertTickElem(vector<int>& _InTicks, int _InOffsetIdx, int _InMajorTickLen)
{

}

void EnglishRuler(int _InMajorTickLen)
{
    vector<int> Ticks;
    const int&& TicksSize = pow(2, _InMajorTickLen - 1) + 1;
    Ticks.reserve(TicksSize);

    InsertTickElem(Ticks, 0, _InMajorTickLen);
    
    for (int i = 0; i < TicksSize; i++)
    {
        for (int i = 0; i < Ticks[i]; i++)
        {
            cout << '-';
        }
        
        cout << '\n' << endl;
    }
}

int main()
{
    int nInput;
    cin >> nInput;
    
    EnglishRuler(nInput);
}
