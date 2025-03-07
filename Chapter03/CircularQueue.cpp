#include "bits/stdc++.h"
using namespace std;

#define CIR_Q_WITH_CIR_ARR 1

#if CIR_Q_WITH_CIR_ARR
template<typename T>
class CircularQueue
{
public:
    bool Enqueue(const T& _InElem);
    bool Dequeue();
    T& Front();

private:

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
