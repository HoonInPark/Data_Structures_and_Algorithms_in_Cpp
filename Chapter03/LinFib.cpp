#include "bits/stdc++.h"
using namespace std;


void WithoutRecursion(int _InFibIdx)
{
    int Former = 0;
    int Later = 1;

    int NumTmp;
    for (int i = 0; i < _InFibIdx - 1; i++)
    {
        NumTmp = Later;
        Later += Former;
        Former = NumTmp;
    }

    cout << Later << endl;
}

// 선형재귀로 피보나치 구현하기
int LinFib(int _InIdx, int _InFormer = 0, int _InLater = 1)
{
    if (_InIdx < 1)
        return _InFormer + _InLater;

    return LinFib(_InIdx - 1, _InLater, _InFormer + _InLater);
}

int main()
{
    // WithoutRecursion(8);

    cout << LinFib(5) << endl;
}
