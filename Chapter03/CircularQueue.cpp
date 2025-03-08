#include "bits/stdc++.h"
using namespace std;

#define CIR_Q_WITH_CIR_ARR 1
#define ARR_SIZE 20

#if CIR_Q_WITH_CIR_ARR
template<typename T>
class CircularQueue
{
public:
    CircularQueue(int _InArrCap = ARR_SIZE)
    {
        m_ArrCap = _InArrCap;
        m_ArrSize = 0;

        m_CirArr = new T*[_InArrCap];
        for (int i = 0; i < _InArrCap; i++)
        {
            m_CirArr[i] = nullptr;
        }
    }
    
    ~CircularQueue()
    {
        for (int i = 0; i < m_ArrCap; i++)
            delete m_CirArr[i];
        
        delete m_CirArr;
    }

    bool Enqueue(const T& _InElem);
    bool Dequeue();
    T& Front();

    inline int Size() const { return m_ArrCap; }
    inline bool IsEmpty() const { return m_ArrCap == 0 ? true : false; }

    inline void CirArrViewer()
    {
        for (int i = 0; i < m_ArrCap; i++)
        {
            if (auto pElem = m_CirArr[i])
                cout << *m_CirArr[i] << ' ';
            else
                cout << '-' << ' ';
        }
    }

private:
    T** m_CirArr;

    int m_ArrCap;
    int m_ArrSize;

    int m_IdxBack{ 0 };
    int m_IdxFront{ 0 };
};
#endif

template<typename T>
bool CircularQueue<T>::Enqueue(const T& _InElem)
{
    if (m_ArrCap <= m_ArrSize) return false;

    m_ArrSize++;
    
    m_CirArr[m_IdxBack % m_ArrCap] = new T(_InElem);
    m_IdxBack++;
    
    return true;
}

template<typename T>
bool CircularQueue<T>::Dequeue()
{
    if (m_ArrSize < 1) return false;
    
    m_ArrSize--;

    delete m_CirArr[m_IdxFront % m_ArrCap];
    m_CirArr[m_IdxFront % m_IdxFront] = nullptr;
    m_IdxFront++;
    return true;
}

template<typename T>
T& CircularQueue<T>::Front()
{
    if (!m_ArrSize)
        throw std::runtime_error("Queue is empty");

    return *m_CirArr[m_IdxFront % m_ArrCap];
}

////////////////////////////////////////////////////////////////////////

int main()
{
    CircularQueue<int>* pCirQ = new CircularQueue<int>();

    for (int i = 0; i < 20; i++)
    {
        pCirQ->Enqueue(i);
    }
    
    for (int i = 0; i < 10; i++)
    {
        pCirQ->Dequeue();
    }
    
    pCirQ->CirArrViewer();
    cout << '\n' << endl;

    do
    {
        cout << pCirQ->Front() << "  ||  ";
        pCirQ->CirArrViewer();
        cout << '\n' << endl;
    } while (pCirQ->Dequeue());

    delete pCirQ;
}
