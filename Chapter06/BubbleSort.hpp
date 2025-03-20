#include "bits/stdc++.h"
using namespace std;

template<typename T>
class Sequence;

/*
 *
 * with Seq class I made, it supports bubble sort algo func
*/
template<typename T>
struct Elem
{
public:
    Elem(const T& _InData = T());
    ~Elem();

private:
    T m_Data;
    Elem* m_pPrev;
    Elem* m_pNext;

    template<typename U>
    friend class Sequence;

};

template<typename T>
Elem<T>::Elem(const T& _InData)
    : m_Data(_InData)
{
}

template<typename T>
Elem<T>::~Elem()
{
}

template<typename T>
class Sequence
{
public:
    Sequence(int _InArrCap = 20);
    ~Sequence();

    void BubbleSort();
    void SeqViewer();

private:
    Elem<T>* m_arrData;

    int m_Cap;
    int m_Size;
};

template<typename T>
Sequence<T>::Sequence(int _InArrCap)
{
    m_arrData = new Elem<T>[_InArrCap];
    m_Cap = _InArrCap;

    if (_InArrCap < 2) return;

    for (int i = 1; i < _InArrCap; i++)
    {
        m_arrData[i - 1].m_pNext = &m_arrData[i];
        m_arrData[i].m_pPrev = &m_arrData[i - 1];
    }
}

template<typename T>
Sequence<T>::~Sequence()
{
    delete[] m_arrData;
}

template<typename T>
inline void Sequence<T>::BubbleSort()
{
}

template<typename T>
inline void Sequence<T>::SeqViewer()
{
}

