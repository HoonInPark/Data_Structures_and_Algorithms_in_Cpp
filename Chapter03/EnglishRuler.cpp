#include "bits/stdc++.h"
using namespace std;

int DrawTickElem(int _InMajorTickLen)
{
    

    return 0;
}

void EnglishRuler(int _InMajorTickNum, int _InMajorTickLen)
{
    for (int i = 0; i < _InMajorTickNum; i++)
    {
        DrawTickElem(_InMajorTickLen);
    }
}

int main()
{
    int nMajorTickNum;
    cin >> nMajorTickNum;
    int nMajorTickLen;
    cin >> nMajorTickLen;
    
    // nMajorTickNum개의 nMajorTickLen만큼의 길이를 갖는 MajorTick이 생긴다.
    EnglishRuler(nMajorTickNum, nMajorTickLen);
}
