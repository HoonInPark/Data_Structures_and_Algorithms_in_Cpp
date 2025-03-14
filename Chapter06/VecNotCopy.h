#include "bits/stdc++.h"
using namespace std;

/*
 * 
 * to avoid copying all the elem in the prev arr for adding new elem over prev cap of arr, 
 * VecNotCopy leaves one last elem (which type is ptr) for make it an 'entrance' for another arr.
*/

template<typename T>
class VecNotCopy
{
public:
    VecNotCopy(int _InCap = 0);
    ~VecNotCopy();

    inline int GetSize() const { return m_Size; }
    inline int GetCap() const { return m_Cap; }
    inline T& operator[](int _InIdx) { return *m_arrData[_InIdx]; }

    bool Add(int _InIdx);
    bool Remove(int _InIdx);

private:
    T** m_arrData;

    int m_Size;
    int m_Cap;
};

template <typename T>
inline VecNotCopy<T>::VecNotCopy(int _InCap)
{
}

template <typename T>
inline VecNotCopy<T>::~VecNotCopy()
{
}

template <typename T>
inline bool VecNotCopy<T>::Add(int _InIdx)
{
    return false;
}

template <typename T>
inline bool VecNotCopy<T>::Remove(int _InIdx)
{
    return false;
}
