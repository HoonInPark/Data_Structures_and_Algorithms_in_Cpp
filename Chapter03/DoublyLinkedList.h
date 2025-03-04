#include "bits/stdc++.h"

template<typename T>
class DoublyLinkedList;

template<typename T>
class Node
{
public:
    Node(const T& _InElem, Node<T>* _pInPrev, Node<T>* _pInNext);
    ~Node();

private:
    const T* m_pElem;

    Node<T>* m_pPrev { nullptr };
    Node<T>* m_pNext { nullptr };

    friend class DoublyLinkedList<T>;
};

////////////////////////////////////////////////////////////////////////////

template<typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    Node<T>* PushBack(const T& _InElem);

#if 0
    void InsertBefore(
        Node<T>* _pInPrev,
        const T& _InElem,
        Node<T>* _pOutPrev = nullptr,
        Node<T>* _pOutNext = nullptr);
#endif // activate if it needed

    Node<T>* Insert(Node<T>* _pInNode, const T& _InElem);

private:
    Node<T>* m_pHeader;
    Node<T>* m_pTrailer;
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

template <typename T>
Node<T>::Node(const T& _InElem, Node<T>* _pInFront, Node<T>* _pInBack)
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
    : m_pHeader(new Node<T>(T(), nullptr, nullptr)),
    m_pTrailer(new Node<T>(T(), nullptr, nullptr))
{
    m_pHeader->m_pNext = m_pTrailer;
    m_pTrailer->m_pPrev = m_pHeader;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node<T>* pNodeTmp = m_pHeader;

    for (;;)
    {
        pNodeTmp = pNodeTmp->m_pNext;
        
        if (!pNodeTmp) return;
        delete pNodeTmp->m_pPrev;
    }
}

template<typename T>
Node<T>* DoublyLinkedList<T>::PushBack(const T& _InElem)
{
    Node<T>* pNewNode = new Node<T>(_InElem, m_pTrailer->m_pPrev, m_pTrailer);

    pNewNode->m_pPrev->m_pNext = pNewNode;
    pNewNode->m_pNext->m_pPrev = pNewNode;

    return pNewNode;
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
Node<T>* DoublyLinkedList<T>::Insert(Node<T>* _pInNode, const T& _InElem)
{
    if (!_pInNode) return nullptr;

    Node<T>* pNewNode = new Node<T>(_InElem, _pInNode->m_pPrev, _pInNode);

    pNewNode->m_pPrev->m_pNext = pNewNode;
    pNewNode->m_pNext->m_pPrev = pNewNode;

    return pNewNode;
}
