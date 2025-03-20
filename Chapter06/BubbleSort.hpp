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
    Elem(Elem* _pInPrev = nullptr, Elem* _pInNext = nullptr, const T& _InData = T());
    ~Elem();

private:
    T m_Data;
    Elem* m_pPrev;
    Elem* m_pNext;

    template<typename U>
    friend class Sequence;
    
};

template<typename T>
Elem<T>::Elem(Elem* _pInPrev, Elem* _pInNext, const T& _InData)
    : m_pPrev(_pInPrev),
    m_pNext(_pInNext),
    m_Data(_InData)
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

private:
    Elem<T>* m_arrData;
};

template<typename T>
Sequence<T>::Sequence(int _InArrCap)
{
    m_arrData = new Elem<T>(_InArrCap);

}

template<typename T>
Sequence<T>::~Sequence()
{
    delete[] m_arrData;
}

