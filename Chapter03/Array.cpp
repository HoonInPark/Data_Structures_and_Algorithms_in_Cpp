#include "bits/stdc++.h"
using namespace std;

#pragma region Elem
class Elem
{
public:
    Elem(const string& _InName = "", int _InValue = 0);

    inline const string& GetName() const { return Name; }
    inline int GetValue() const { return Value; }

    Elem& operator=(const Elem& _Rhs)
    {
        Name = _Rhs.Name;
        Value = _Rhs.Value;
        return *this;
    }

private:
    string Name;
    int Value;
};

Elem::Elem(const string &_InName, int _InValue)
    : Name(_InName), Value(_InValue)
{
}
#pragma endregion Elem

#pragma region Array
// highest score must be at the begin of the array
class Array
{
public:
    Array(int _InCap);
    ~Array();

    inline int GetSize() const { return Size; }
    inline int GetCap() const { return Cap; }
    inline Elem& operator[](int _InIndex) { return Data[_InIndex]; }

    bool Add(const Elem& _InElem);
    bool Remove(int _Idx);

private:
    Elem* Data;

    int Size;
    int Cap;
};

Array::Array(int _InCap)
    : Cap(_InCap)
{
    Size = 0;
    Data = new Elem[Cap];
}

Array::~Array()
{
    delete[] Data;
}

bool Array::Add(const Elem &_InElem)
{
    int nWhereToStartPush = Size - 1;
    if (Size == Cap)
    {
        if (Data[Size - 1].GetValue() > _InElem.GetValue())
            return false;
        else
            nWhereToStartPush--;
    }
    else Size++;

    /*
    먼저 어디에 넣을지를 찾아야 한다.
    반복문을 돌면서 크기 비교를 한다. 
    그리고 넣어야 하는데, 만약 인덱스가 더 큰 곳에 엘레먼트가 있으면 한칸씩 뒤로 밀어야.
    */
    int IdxToInsert = 0;

#pragma region general case
    for (int i = Size - 2; i > -1; i--)
    {
        if (Data[i].GetValue() > _InElem.GetValue())
        {
            IdxToInsert = i + 1;
            break;
        }
    }
#pragma endregion general case

    for (int i = nWhereToStartPush; i > IdxToInsert - 1; i--)
        Data[i + 1] = Data[i];

    Data[IdxToInsert] = _InElem;

    return true;
}

bool Array::Remove(int _Idx)
{
    try
    {
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return false;
}
#pragma endregion Array

int main()
{
    Array arr(10);
    arr.Add(Elem("A", 100));
    arr.Add(Elem("B", 10));
    arr.Add(Elem("C", 1000));
    arr.Add(Elem("D", 10000));

    for (int i = 0; i < arr.GetSize(); i++)
        cout << arr[i].GetName() << " " << arr[i].GetValue() << endl;
}
