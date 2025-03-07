#include "bits/stdc++.h"
using namespace std;

/// @brief print all the cases consist of k num of chars which are elem of U
/// @param k 
/// @param S string arr that buffers chars from U
/// @param U 
void PuzzleSolve(int k, vector<int>& S, unordered_set<int>& U)
{
    
}

int main()
{
    unordered_set<int> U = { 11, 23, 31, 42 }; // 사용 가능한 숫자 집합
    vector<int> S;  // 선택한 숫자 순열
    int k = 3;  // 3개 숫자로 이루어진 모든 순열 찾기

    PuzzleSolve(k, S, U);

    return 0;
}
