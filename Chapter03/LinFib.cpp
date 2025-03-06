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
int LinFib(int _InFormer, int _InLater, int _InIdx)
{
    if (_InIdx < 1)
        return _InFormer + _InLater;

    return LinFib(_InLater, _InFormer + _InLater, _InIdx - 1);
}

int main()
{
    // WithoutRecursion(8);

    int Former = 0;
    int Later = 1;

    cout << LinFib(0, 1, 4) << endl;
}
