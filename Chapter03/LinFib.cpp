#include "bits/stdc++.h"
using namespace std;


void WithoutRecursion(int _InFibIdx)
{
    int Former = 0;
    int Later = 1;

    for (int i = 0; i < _InFibIdx + 1; i++)
    {
        int NumTmp = Later;
        Later = Former + Later;
        Former = NumTmp;
    }

    cout << Later << endl;
}

// 선형재귀로 피보나치 구현하기
int LinFib(int _InFibIdx)
{
    if (_InFibIdx < 2) return 1;

    
}

int main()
{
    WithoutRecursion(5);
}
