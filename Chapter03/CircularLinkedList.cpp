#define CURSOR_USED_ONLY_AS_SEARCH_PT 0

#include "bits/stdc++.h"
using namespace std;

typedef int Elem;

class CirList;

class Node
{
public:
    Node(const Elem& _InElem) : m_Elem(_InElem) {}

private:
    Elem m_Elem;

    Node* m_pNext{nullptr};

    friend CirList;
};

class CirList
{
public:
    CirList() {}
    ~CirList()
    {
        Node* pNodeFormerTmp = m_pCursor;
        Node* pNodeLaterTmp;
        
        while (pNodeFormerTmp)
        {
            pNodeLaterTmp = pNodeFormerTmp->m_pNext;
            delete pNodeFormerTmp;
            
            pNodeFormerTmp = pNodeLaterTmp;
        }
    }

    bool Add(const Elem& _InElem)
    {
        auto pNodeGen = new Node(_InElem);

        if (!m_pCursor)
        {
            pNodeGen->m_pNext = pNodeGen;
            m_pCursor = pNodeGen;

            return true;
        }
        else
        {
            pNodeGen->m_pNext = m_pCursor->m_pNext;
            m_pCursor->m_pNext = pNodeGen;
            m_pCursor = pNodeGen;

            return true;
        }
    }

    void PrintNode(Node* _pInNode) { cout << _pInNode->m_Elem << endl; }

    inline Node* GetNextNode(Node* _pInNode) { return _pInNode->m_pNext; }
    inline Node* GetCursor() { return m_pCursor; }

private:
    Node* m_pCursor{nullptr};
};

int main()
{
    auto pCirListGen = new CirList();
    
    for (int i = 0; i < 100; i++)
    {
        pCirListGen->Add(i);
    }

    Node* NodeTmp = pCirListGen->GetCursor();
    for (int i = 0; i < 200; i++)
    {
        pCirListGen->PrintNode(NodeTmp);
        NodeTmp = pCirListGen->GetNextNode(NodeTmp);
    }

    delete pCirListGen;
}

/* 
 * 질문 : circular list에서 advance의 동작은 어떻게 이루어지는가? 
 * cursor가 가리키는 노드는 어떻게 변하는가? 
 * 이것은 언제나 back을 가리키고, 이것 뒤에 front가 있어야 하나?
 * advance가 일어나면 이 관계는 유지한 채로 front외 back이 가리키는 노드가 바뀌나?
 * front외 back은 그냥 cursor를 기준으로 앞 뒤를 부르는 이름이고, 따로 포인터를 저장하거나 하지는 않는다. 
*/
