#include "bits/stdc++.h"
using namespace std;

class InsertSortArr
{
public:
    InsertSortArr(int _InCap);
    ~InsertSortArr();

    inline int GetElem(int _Idx) const { return Data[_Idx]; }

    inline int GetSize() const { return Size; }
    inline int GetCap() const { return Cap; }

    bool Add(const int _InElem);

private:
    void Sort();

private:
    int* Data;

    int Size;
    int Cap;
};

InsertSortArr::InsertSortArr(int _InCap)
    : Cap(_InCap)
{
    Size = 0;
    Data = new int[Cap];
}

InsertSortArr::~InsertSortArr()
{
    delete[] Data;
}

bool InsertSortArr::Add(const int _InElem)
{
    if (Size == Cap)
        return false;

    if (Size < 1)
    {
        Data[0] = _InElem;
        Size++;

        return true;
    }

    // 여기까지 왔으면 원소의 갯수가 1개 이상이고 삽입할 공간이 있다는 것이다.
    Data[Size] = _InElem;
    Size++;
    Sort();

    return true;
}

void InsertSortArr::Sort()
{
    int CurIdx = Size - 1;
    while (CurIdx > 0)
    {
        if (Data[CurIdx] < Data[CurIdx - 1])
        {
            int ElemTmp = Data[CurIdx - 1];
            Data[CurIdx - 1] = Data[CurIdx];
            Data[CurIdx] = ElemTmp;

            break;
        }

        CurIdx--;
    }
}

int main()
{
    InsertSortArr Arr(10);

    Arr.Add(3);
    Arr.Add(1);
    Arr.Add(2);
    Arr.Add(5);
    Arr.Add(4);

    for (int i = 0; i < Arr.GetSize(); i++)
    {
        cout << Arr.GetElem(i) << " ";
    }

    cout << "" << endl;

    return 0;
}

