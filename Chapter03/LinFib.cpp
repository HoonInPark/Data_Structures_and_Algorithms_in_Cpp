#include "bits/stdc++.h"
using namespace std;

#if 0
// 선형재귀로 피보나치 구현하기
int LinFib(int _InFibIdx)
{
    if (_InFibIdx < 2) return 1;


}
#endif

void WithoutRecurse(int _InFibIdx)
{
    int Former = 0;
    int Later = 1;

    for (int i = 0; i < _InFibIdx; i++)
    {
        Later = Former + Later;
        
    }
}

int main()
{
    
}
