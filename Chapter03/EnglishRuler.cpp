#include "bits/stdc++.h"
using namespace std;

void InsertTickElem(int _InMajorTickNum, vector<int>& _InTicks)
{
    
}

void EnglishRuler(int _InMajorTickNum)
{
    vector<int> Ticks;
    Ticks.reserve(pow(2, _InMajorTickNum - 1) + 1);

    InsertTickElem(_InMajorTickNum, Ticks);
    
    const int&& TicksSize = Ticks.size();
    for (int i = 0; i < TicksSize; i++)
    {
        cout << Ticks[i] << endl;
    }
}

int main()
{
    int nInput;
    cin >> nInput;
    
    EnglishRuler(nInput);
}
