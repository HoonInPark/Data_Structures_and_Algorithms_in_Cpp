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

////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

template<typename T>
Node<T>::Node(const T& _InElem)
: m_Elem(_InElem)
{
}

////////////////////////////////////////////////////////////////////////

template<typename T>
CirList<T>::CirList()
{
}

template<typename T>
CirList<T>::~CirList()
{
    Node<T>* pNodeForTmp = m_pCursor->m_pNext;
    m_pCursor->m_pNext = nullptr;

    Node<T>* pNodeLatTmp;

    while (pNodeForTmp)
    {
        pNodeLatTmp = pNodeForTmp->m_pNext;
        delete pNodeForTmp;

        pNodeForTmp = pNodeLatTmp;
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
