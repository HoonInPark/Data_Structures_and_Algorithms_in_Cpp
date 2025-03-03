#include "bits/stdc++.h"
#include "DoublyLinkedList.cpp"
using namespace std;

void InsertTickElem(list<int>& _InTicks, int _InMajorTickLen, _List_iterator<int> _InIter)
{
}

void EnglishRuler(int _InMajorTickLen)
{
    list<int> Ticks;
    
    Ticks.push_front(_InMajorTickLen);
    InsertTickElem(Ticks, _InMajorTickLen, Ticks.end());
}

int main()
{
    int nInput;
    cin >> nInput;
    
    EnglishRuler(nInput);
}
