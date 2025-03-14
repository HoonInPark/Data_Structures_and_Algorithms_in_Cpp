#include "bits/stdc++.h"
using namespace std;

/*
 *
 * theme : FUCK std::vector
 * to avoid copying all the elem in the prev arr for adding new elem over prev cap of arr,
 * VecNotCopy leaves one last elem (which type is ptr) for make it an 'entrance' for another arr.
 */

template <typename T>
class VecNotCopy
{
public:
    VecNotCopy(int _InInitCap = 20);
    VecNotCopy(const VecNotCopy& _Rhs);
    ~VecNotCopy();

    inline int GetSize() const { return m_Size; }
    inline int GetCap() const { return m_Cap; }
    inline T& operator[](int _InIdx) { return m_arrData[_InIdx]; }

    bool Reserve(int _InCap);

    bool PushBack(const T& _InElem);
    bool Remove(int _InIdx);

private:
    T* m_arrData;

    const int m_Cap;
    int m_Size{ 0 };
};

template <typename T>
inline VecNotCopy<T>::VecNotCopy(int _InInitCap)
    : m_Cap(_InInitCap)
{
    m_arrData = new T[_InInitCap];

    for (auto& Elem : m_arrData)
        Elem = T();
}

template<typename T>
inline VecNotCopy<T>::VecNotCopy(const VecNotCopy& _Rhs)
{
}

template <typename T>
inline VecNotCopy<T>::~VecNotCopy()
{
}

template<typename T>
inline bool VecNotCopy<T>::Reserve(int _InCap)
{
    return false;
}

template <typename T>
bool VecNotCopy<T>::PushBack(const T& _InElem)
{
    if (m_Size < m_Cap)
    {


        m_Size++;
        return true;
    }
    else
    {
        /* alloc another arr code */
        return true;
    }
}

template <typename T>
inline bool VecNotCopy<T>::Remove(int _InIdx)
{
    return false;
}
