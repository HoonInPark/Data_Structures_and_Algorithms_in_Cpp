#include "DoublyLinkedList.h"
using namespace std;

void InsertTickElem(DoublyLinkedList<int>& _InTicks, int _InMajorTickLen, Node<int>* _pInNode)
{

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
