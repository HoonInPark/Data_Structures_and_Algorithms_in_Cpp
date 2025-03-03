class DounblyLinkedList;

template<typename T>
class Node
{
public:
    Node(const T& _InElem);
    ~Node();
    
private:
    const T* m_pElem;

    Node* m_pFront;
    Node* m_pBack;
    
    friend DounblyLinkedList;
};

template<typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

private:
    T m_Elem;
};
