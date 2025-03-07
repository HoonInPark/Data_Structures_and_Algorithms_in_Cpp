#include "bits/stdc++.h"
using namespace std;

void PuzzleSolve(int k, vector<int>& S, unordered_set<int>& U)
{
    if (k == 0)
    {
        // 길이가 원하는 만큼 되면 결과 출력
        cout << "Solution found: ";

        for (int num : S)
            cout << num << " ";

        cout << endl;

        return;
    }

    // 인수로 들어온 U는 첫번째 depth에선 4, 그 다음은 3, 2, 1개가 된다. 
    // 각 depth에서는 거기서 하나씩 빼고 string 배열을 나타내는 S에 대입
    unordered_set<int> U_Buffer(U);

    for (auto& e : U)
    {
        U_Buffer.erase(e);   // 사용한 원소 제거
        S.push_back(e); // 원소 추가

        PuzzleSolve(k - 1, S, U_Buffer); // 재귀 호출

        S.pop_back(); // 백트래킹: 원소 제거
        U_Buffer.insert(e);  // 다시 사용 가능하도록 복구
    }
}

int main()
{
    unordered_set<int> U = { 11, 23, 31, 42 }; // 사용 가능한 숫자 집합
    vector<int> S;  // 선택한 숫자 순열
    int k = 3;  // 3개 숫자로 이루어진 모든 순열 찾기

    PuzzleSolve(k, S, U);

    return 0;
}
