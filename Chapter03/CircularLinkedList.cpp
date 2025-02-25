#include "bits/stdc++.h"
using namespace std;

typedef int Elem;

class CircularList;

class Node
{
public:
    Node(const Elem& _InElem) : m_Elem(_InElem) {}

private:
    Elem m_Elem;
    Node* m_pNext{nullptr};

    friend CircularList;
};

class CircularList
{
public:
    bool Add(Node* _pInNode)
    {
        if (!m_pFront)
        {
            

            return true;
        }
        else
        {
            return true;
        }
        
        return false;
    }

    void PrintNode(Node* _pInNode) { cout << _pInNode->m_Elem << endl; }

    inline Node* GetNextNode(Node* _pInNode) { return _pInNode->m_pNext; }
    inline Node* GetCursor() { return m_pCursor; }

private:
    Node* m_pFront{nullptr};
    Node* m_pBack{nullptr};

    Node* m_pCursor{nullptr};
};

int main()
{
    CircularList* CircularLinkedListGen;
    for (int i = 0; i < 100; i++)
    {
        CircularLinkedListGen->Add(new Node(i));
    }

    Node* NodeTmp = CircularLinkedListGen->GetCursor();
    for (int i = 0; i < 200; i++)
    {
        CircularLinkedListGen->PrintNode(NodeTmp);
        NodeTmp = CircularLinkedListGen->GetNextNode(NodeTmp);
    }
}
