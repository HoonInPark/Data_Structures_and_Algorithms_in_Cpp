#include "BubbleSort.hpp"

int main()
{
    Sequence<int>* SeqTest = new Sequence<int>(6);

    vector<int> VecTmp = { 5, 7, 2, 6, 9, 3 };
    for (int i = 0; i < 6; i++)
    {
        SeqTest->PushBack(&VecTmp[i]);
    }
    
    SeqTest->SeqViewer();
    SeqTest->BubbleSort();

    cout << "==================================" << endl;
    SeqTest->SeqViewer();

    delete SeqTest;
}
