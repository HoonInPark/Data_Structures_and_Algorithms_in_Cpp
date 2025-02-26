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
            m_pFront = _pInNode;

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
    CircularList CircularListGen;
    
    for (int i = 0; i < 100; i++)
    {
        CircularListGen.Add(new Node(i));
    }

    Node* NodeTmp = CircularListGen.GetCursor();
    for (int i = 0; i < 200; i++)
    {
        CircularListGen.PrintNode(NodeTmp);
        NodeTmp = CircularListGen.GetNextNode(NodeTmp);
    }
}
