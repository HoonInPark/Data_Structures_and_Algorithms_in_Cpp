#include "CircularLinkedList.h"

int main()
{
    auto pCirListGen = new CirList<int>();

    for (int i = 0; i < 100; i++)
    {
        pCirListGen->Add(i);
    }

    Node<int>* NodeTmp = pCirListGen->GetCursor();
    for (int i = 0; i < 200; i++)
    {
        pCirListGen->PrintNode(NodeTmp);
        NodeTmp = pCirListGen->GetNextNode(NodeTmp);
    }

    delete pCirListGen;
}