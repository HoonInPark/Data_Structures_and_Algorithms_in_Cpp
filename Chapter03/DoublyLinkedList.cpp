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
    m_pHeader->m_pNext = m_pTrailer;
    m_pTrailer->m_pPrev = m_pHeader;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node<T>* pNodeTmp = m_pHeader;

    do
    {
        pNodeTmp = pNodeTmp->m_pNext;
        delete pNodeTmp->m_pPrev;
    } while (!pNodeTmp);
}

#if 0
template<typename T>
void DoublyLinkedList<T>::InsertBefore(
    Node<T>* _pInPrev,
    const T& _InElem,
    Node<T>* _pOutPrev,
    Node<T>* _pOutNext)
{
}
#endif

template <typename T>
void DoublyLinkedList<T>::InsertAfter(
    Node<T>* _pInNext,
    const T& _InElem,
    Node<T>* _pOutPrev,
    Node<T>* _pOutNext)
{
    if (!_pInNext) return;

    auto pNewNode = new Node(_InElem, _pInNext->m_pPrev, _pInNext);
    _pOutPrev = pNewNode->m_pPrev;
    _pOutNext = pNewNode->m_pNext;

    pNewNode->m_pPrev->m_pNext = pNewNode;
    pNewNode->m_pNext->m_pPrev = pNewNode;
}
