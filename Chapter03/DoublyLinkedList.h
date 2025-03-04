class DounblyLinkedList;

template<typename T>
class Node
{
public:
    Node(const T& _InElem, Node* _pInPrev, Node* _pInNext);
    ~Node();
    
private:
    const T* m_pElem;

    Node* m_pPrev;
    Node* m_pNext;
    
    friend DounblyLinkedList;
};

////////////////////////////////////////////////////////////////////////////

template<typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void Add(
        const T& _InElem, 
        Node<T>* _pOutPrev = nullptr, 
        Node<T>* _pOutNext = nullptr);

private:
    Node<T>* m_pHeader;
    Node<T>* m_pTrailer;
};
