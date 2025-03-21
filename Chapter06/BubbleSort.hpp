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
    Elem(T* _pInData = nullptr);
    ~Elem();

private:
    T* m_pData;
    Elem* m_pPrev;
    Elem* m_pNext;

    template<typename U>
    friend class Sequence;

};

template<typename T>
Elem<T>::Elem(T* _pInData)
    : m_pData(_pInData)
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

    bool PushBack(T* _pInData);

    void BubbleSort();
    void SeqViewer();

private:
    bool BubbleSortPass();

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
    m_Size = 0;

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
bool Sequence<T>::PushBack(T* _pInData)
{
    m_arrData[m_Size].m_pData = _pInData;
    m_Size++;

    return true;
}

template<typename T>
void Sequence<T>::BubbleSort()
{
    for (;;)
    {
        if (!BubbleSortPass()) return;
    }
}

template<typename T>
bool Sequence<T>::BubbleSortPass()
{
    bool bIsSortDone = true;
    T* pTmpData;

    for (int i = 1; i < m_Size; i++)
    {
        if (*m_arrData[i - 1].m_pData > *m_arrData[i].m_pData)
        {
            bIsSortDone = false;

        }
        else
        {
            
        }
    }

    return bIsSortDone;
}

template<typename T>
void Sequence<T>::SeqViewer()
{
    for (int i = 0; i < m_Size; i++)
    {
        cout << *m_arrData[i].m_pData << " , ";
    }    
}
