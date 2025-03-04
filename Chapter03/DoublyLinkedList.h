class DounblyLinkedList;

template<typename T>
class Node
{
public:
    Node(const T& _InElem, Node* _pInPrev, Node* _pInNext);
    ~Node();

private:
    const T* m_pElem;

    Node* m_pPrev { nullptr };
    Node* m_pNext { nullptr };

    friend DounblyLinkedList;
};

////////////////////////////////////////////////////////////////////////////

template<typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

#if 0
    void InsertBefore(
        Node<T>* _pInPrev,
        const T& _InElem,
        Node<T>* _pOutPrev = nullptr,
        Node<T>* _pOutNext = nullptr);
#endif // activate if it needed

    void InsertAfter(
        Node<T>* _pInNext,
        const T& _InElem,
        Node<T>* _pOutPrev = nullptr,
        Node<T>* _pOutNext = nullptr);

private:
    Node<T>* m_pHeader;
    Node<T>* m_pTrailer;
};
