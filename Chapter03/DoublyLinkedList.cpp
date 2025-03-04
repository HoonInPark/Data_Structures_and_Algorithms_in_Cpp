#include "DoublyLinkedList.h"

#include "bits/stdc++.h"
using namespace std;

template <typename T>
Node<T>::Node(const T& _InElem, Node* _pInFront, Node* _pInBack)
    : m_pElem(new T(_InElem)),
      m_pPrev(_pInFront),
      m_pNext(_pInBack)
{
}

template<typename T>
Node<T>::~Node()
{
    delete m_pElem;
}

////////////////////////////////////////////////////////////////////////////

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
    : m_pHeader(new Node(T(), nullptr, nullptr)),
      m_pTrailer(new Node(T(), nullptr, nullptr))
{
    m_pHeader->m_pPrev = nullptr;
    m_pHeader->m_pNext = m_pTrailer;

    m_pTrailer->m_pPrev = m_pHeader;
    m_pTrailer->m_pNext = nullptr;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node<T>* pNodeTmp = m_pHeader;
    
    do
    {
        pNodeTmp = pNodeTmp->m_pNext;
        delete pNodeTmp->m_pPrev;
    }
    while (!pNodeTmp);
}

template <typename T>
void DoublyLinkedList<T>::Add(const T &_InElem, Node<T> *_pOutPrev, Node<T> *_pOutNext)
{
}
