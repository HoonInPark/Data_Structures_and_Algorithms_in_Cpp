#include "bits/stdc++.h"
using namespace std;

#define CIR_Q_WITH_CIR_ARR 1
#define ARR_SIZE 100

#if CIR_Q_WITH_CIR_ARR
template<typename T>
class CircularQueue
{
public:
    CircularQueue(int _InArrSize = ARR_SIZE)
    {
        m_ArrSize = _InArrSize;
        m_CirArr = new T[_InArrSize];
    }
    ~CircularQueue()
    {
        delete[] m_CirArr;
    }

    bool Enqueue(const T& _InElem);
    bool Dequeue();
    T& Front();

    inline int Size() const { return m_ArrSize; }
    inline bool IsEmpty() const { return m_ArrSize == 0 ? true : false; }

private:
    T* m_CirArr;

    int m_ArrSize;

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
    return false;
}

template<typename T>
bool CircularQueue<T>::Dequeue()
{
    return false;
}

template<typename T>
T& CircularQueue<T>::Front()
{
    // TODO: 여기에 return 문을 삽입합니다.
}
