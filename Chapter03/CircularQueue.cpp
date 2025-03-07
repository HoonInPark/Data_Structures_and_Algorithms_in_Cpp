#include "bits/stdc++.h"
using namespace std;

#define CIR_Q_WITH_CIR_ARR 1
#define ARR_SIZE 20

#if CIR_Q_WITH_CIR_ARR
template<typename T>
class CircularQueue
{
public:
    CircularQueue(int _InArrSize = ARR_SIZE)
    {
        m_ArrCap = _InArrSize;
        m_Arrsize = 0;

        m_CirArr = new T[_InArrSize];
    }
    ~CircularQueue()
    {
        delete[] m_CirArr;
    }

    bool Enqueue(const T& _InElem);
    bool Dequeue();
    T& Front();

    inline int Size() const { return m_ArrCap; }
    inline bool IsEmpty() const { return m_ArrCap == 0 ? true : false; }

private:
    T* m_CirArr;

    int m_ArrCap;
    int m_Arrsize;

    int m_IdxBack{ 0 };
    int m_IdxFront{ 0 };
};
#endif

int main()
{

}

template<typename T>
bool CircularQueue<T>::Enqueue(const T& _InElem)
{
    if (m_ArrCap <= m_Arrsize)
        return false;


    m_IdxBack++;
    return true;
}

template<typename T>
bool CircularQueue<T>::Dequeue()
{
    if (m_Arrsize < 1) return false;
    
    //
    m_IdxFront++;
    return true;
}

template<typename T>
T& CircularQueue<T>::Front()
{
    return m_CirArr[m_IdxFront % m_ArrCap];
}
