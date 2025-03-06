#include "DoublyLinkedList.h"
using namespace std;

void InsertTickElem(DoublyLinkedList<int>& _InTicks, int _InMajorTickLen, Node<int>* _pInNode)
{
    if (_InMajorTickLen < 2) return;

    InsertTickElem(_InTicks, _InMajorTickLen - 1, _InTicks.Insert(_pInNode, _InMajorTickLen - 1));
    InsertTickElem(_InTicks, _InMajorTickLen - 1, _pInNode);
}

void EnglishRuler(int _InMajorTickLen)
{
    auto pTicks = new DoublyLinkedList<int>();

    pTicks->PushBack(_InMajorTickLen);
    InsertTickElem(*pTicks, _InMajorTickLen, pTicks->PushBack(_InMajorTickLen));

    delete pTicks;
}

int main()
{
    int nInput;
    cin >> nInput;

    EnglishRuler(nInput);
}
