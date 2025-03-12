#define CURSOR_USED_ONLY_AS_SEARCH_PT 0

#include "bits/stdc++.h"
using namespace std;

template<typename T>
class CirList;

template<typename T>
class Node
{
public:
    Node(const T& _InElem);

private:
    T m_Elem;

    Node* m_pNext{ nullptr };

    template<typename U>
    friend class CirList;
};

template<typename T>
class CirList
{
public:
    CirList();
    ~CirList();

    bool Add(const T& _InElem);

    inline void PrintNode(Node<T>* _pInNode) { cout << _pInNode->m_Elem << endl; }

    inline Node<T>* GetNextNode(Node<T>* _pInNode) { return _pInNode->m_pNext; }
    inline Node<T>* GetCursor() { return m_pCursor; }

private:
    Node<T>* m_pCursor{ nullptr };
};

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

/*
 * 질문 : circular list에서 advance의 동작은 어떻게 이루어지는가?
 * cursor가 가리키는 노드는 어떻게 변하는가?
 * 이것은 언제나 back을 가리키고, 이것 뒤에 front가 있어야 하나?
 * advance가 일어나면 이 관계는 유지한 채로 front외 back이 가리키는 노드가 바뀌나?
 * front외 back은 그냥 cursor를 기준으로 앞 뒤를 부르는 이름이고, 따로 포인터를 저장하거나 하지는 않는다.
 */

template<typename T>
Node<T>::Node(const T& _InElem)
    : m_Elem(_InElem)
{

}

template<typename T>
CirList<T>::CirList()
{
}

template<typename T>
CirList<T>::~CirList()
{
    Node<T>* pNodeFormerTmp = m_pCursor;
    Node<T>* pNodeLaterTmp;

    while (pNodeFormerTmp)
    {
        pNodeLaterTmp = pNodeFormerTmp->m_pNext;
        delete pNodeFormerTmp;

        pNodeFormerTmp = pNodeLaterTmp;
    }
}

template<typename T>
bool CirList<T>::Add(const T& _InElem)
{
    auto pNodeGen = new Node<T>(_InElem);

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
