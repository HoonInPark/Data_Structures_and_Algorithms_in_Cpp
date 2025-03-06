#include "bits/stdc++.h"
using namespace std;

int BinarySum(const vector<int>& _InVec, int _InIdx, int _InNum) 
{
    if (_InNum == 1) return _InVec[_InIdx];  // 기저 조건: 원소 1개 남으면 그대로 반환

    int mid = _InNum / 2;
    return BinarySum(_InVec, _InIdx, mid) + BinarySum(_InVec, _InIdx + mid, _InNum - mid);
}

int main() 
{
    vector<int> Vec = {1, 2, 3, 4, 5, 6, 7, 8}; // 예제 배열
    int result = BinarySum(Vec, 0, Vec.size());  // 전체 배열 합 구하기

    cout << "Sum of array: " << result << endl; // 출력: 36
}
