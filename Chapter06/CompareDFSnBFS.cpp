#include <iostream>
#include <ctime>
#include <queue>

using namespace std;

struct NodeStruct
{
    int bIsVisited;

    NodeStruct* pFrontNode;
    NodeStruct* pBackNode_L;
    NodeStruct* pBackNode_R;

    NodeStruct()
    {
        bIsVisited = 0;
        pFrontNode = nullptr;
        pBackNode_L = nullptr;
        pBackNode_R = nullptr;
    }
};

class BinTree
{
public:
    inline NodeStruct* GetBinTree()
    {
        return pTree;
    }

    inline void SetBinTree(const int& _rNumOfNodes)
    {
        pTree = new NodeStruct;
        MakeNodes_loop(_rNumOfNodes, pTree);
    }

    void DFS_rec(NodeStruct*& _prTree);

    void DFS_loop(NodeStruct* _pTree);

    void BFS_rec(queue<NodeStruct*>& _rVisitedQueue);
    void BFS_loop(NodeStruct* _pTree);

private:
    NodeStruct* pTree{};

    void MakeNodes_rec(int _NumOfNodes, NodeStruct*& _prNodeSelf);

    void MakeNodes_loop(int _NumOfNodes, NodeStruct* _pNodeSelf);
};

void BinTree::MakeNodes_rec(int _NumOfNodes, NodeStruct*& _prNodeSelf)
{
    if (_NumOfNodes > 0)
    {
        _NumOfNodes--;
        auto* pBackNode_L = new NodeStruct;
        pBackNode_L->pFrontNode = _prNodeSelf;

        _prNodeSelf->pBackNode_L = pBackNode_L;
        MakeNodes_rec(_NumOfNodes, pBackNode_L);

        auto* pBackNode_R = new NodeStruct;
        pBackNode_R->pFrontNode = _prNodeSelf;

        _prNodeSelf->pBackNode_R = pBackNode_R;
        MakeNodes_rec(_NumOfNodes, pBackNode_R);
    }
}

void BinTree::MakeNodes_loop(int _NumOfNodes, NodeStruct* _pNodeSelf)
{
    queue<NodeStruct*> QueueOfNodes;
    QueueOfNodes.push(_pNodeSelf);
    _NumOfNodes--; // 이미 하나 만들었으니까 1을 빼준다.

    NodeStruct* pNodeOfQueue;
    while (!QueueOfNodes.empty())
    {
        // 우선 while 스코프 내에서만 쓰이는 변수에 담는다.
        pNodeOfQueue = QueueOfNodes.front();
        // 그리고 담았으니 큐에서 삭제
        QueueOfNodes.pop();

        /////////////////////////////////////////// Left ///////////////////////////////////////////
        _NumOfNodes--;
        if (_NumOfNodes < 0) break;

        auto* pLeftNode = new NodeStruct;
        pNodeOfQueue->pBackNode_L = pLeftNode;
        pLeftNode->pFrontNode = pNodeOfQueue;

        QueueOfNodes.push(pLeftNode);
        ////////////////////////////////////////////////////////////////////////////////////////////


        /////////////////////////////////////////// Right ///////////////////////////////////////////
        _NumOfNodes--;
        if (_NumOfNodes < 0) break;

        auto* pRightNode = new NodeStruct;
        pNodeOfQueue->pBackNode_R = pRightNode;
        pRightNode->pFrontNode = pNodeOfQueue;

        QueueOfNodes.push(pRightNode);
        ////////////////////////////////////////////////////////////////////////////////////////////
    }

    while (!QueueOfNodes.empty()) QueueOfNodes.pop();
    pNodeOfQueue = nullptr;
    delete pNodeOfQueue;
}

void BinTree::DFS_rec(NodeStruct*& _prTree)
{
    _prTree->bIsVisited = 1;

    if (_prTree->pBackNode_L && _prTree->pBackNode_L->bIsVisited != 1)
    {
        // 왼쪽으로 타고 내려가는 로직
        DFS_rec(_prTree->pBackNode_L);
    }
    else if (_prTree->pBackNode_R && _prTree->pBackNode_R->bIsVisited != 1)
    {
        // 오른쪽으로 타고 내려가는 로직
        DFS_rec(_prTree->pBackNode_R);
    }
    else if (_prTree->pFrontNode) // 올라가는 로직
    {
        DFS_rec(_prTree->pFrontNode);
    }
}

void BinTree::DFS_loop(NodeStruct* _pTree)
{
    _pTree->bIsVisited = 1;
    NodeStruct*& pNode_temp = _pTree;

    for (;;)
    {
        if (pNode_temp->pBackNode_L && pNode_temp->pBackNode_L->bIsVisited != 1)
        {
            // 왼쪽으로 타고 내려가는 로직
            pNode_temp->pBackNode_L->bIsVisited = 1;
            pNode_temp = pNode_temp->pBackNode_L;
        }
        else if (pNode_temp->pBackNode_R && pNode_temp->pBackNode_R->bIsVisited != 1)
        {
            // 오른쪽으로 타고 내려가는 로직
            pNode_temp->pBackNode_R->bIsVisited = 1;
            pNode_temp = pNode_temp->pBackNode_R;
        }
        else if (pNode_temp->pFrontNode) // 올라가는 로직
        {
            pNode_temp = pNode_temp->pFrontNode;
        }
        else break;
    }

    pNode_temp = nullptr;
    delete pNode_temp;
}

void BinTree::BFS_rec(queue<NodeStruct*>& _rVisitedQueue)
{
    if (_rVisitedQueue.empty()) return;

    auto pNodeOfQueue = _rVisitedQueue.front();
    _rVisitedQueue.pop();

    pNodeOfQueue->bIsVisited = 1;
    if (pNodeOfQueue->pBackNode_L) _rVisitedQueue.push(pNodeOfQueue->pBackNode_L);
    if (pNodeOfQueue->pBackNode_R) _rVisitedQueue.push(pNodeOfQueue->pBackNode_R);

    pNodeOfQueue = nullptr;
    delete pNodeOfQueue;

    BFS_rec(_rVisitedQueue);
}

void BinTree::BFS_loop(NodeStruct* _pTree)
{
    queue<NodeStruct*> QueueOfNodes;
    QueueOfNodes.push(_pTree);

    NodeStruct* pNode_temp;
    while (!QueueOfNodes.empty())
    {
        pNode_temp = QueueOfNodes.front();
        QueueOfNodes.pop();

        pNode_temp->bIsVisited = 1;
        if (pNode_temp->pBackNode_L) QueueOfNodes.push(pNode_temp->pBackNode_L);
        if (pNode_temp->pBackNode_R) QueueOfNodes.push(pNode_temp->pBackNode_R);
    }

    pNode_temp = nullptr;
    delete pNode_temp;
    while (!QueueOfNodes.empty()) QueueOfNodes.pop();
}

int main()
{
    int num;
    cout << "Type Number : ";
    cin >> num;
/*
    //////////////////////////////////////////////////////////////
    BinTree TreeTest_02;
    TreeTest_02.SetBinTree(num);

    clock_t start_02, finish_02;
    double duration_02;

    NodeStruct* pBinTree_02 = TreeTest_02.GetBinTree();
    start_02 = clock();
    TreeTest_02.DFS_loop(pBinTree_02);
    finish_02 = clock();
    duration_02 = (double) (finish_02 - start_02);

    //////////////////////////////////////////////////////////////
    BinTree TreeTest_02;
    TreeTest_02.SetBinTree(num);

    clock_t start_02, finish_02;
    double duration_02;

    NodeStruct* pBinTree_02 = TreeTest_02.GetBinTree();
    start_02 = clock();
    TreeTest_02.DFS_rec(pBinTree_02);
    finish_02 = clock();
    duration_02 = (double) (finish_02 - start_02);

    cout << "time spent on recursive DFS : " << duration_02 << endl;
    cout << "time spent on loop DFS : " << duration_02 << endl;
*/

    //////////////////////////////////////////////////////////////
    BinTree TreeTest_01;
    TreeTest_01.SetBinTree(num);

    clock_t start_01, finish_01;
    double duration_01;

    NodeStruct* pBinTree_01 = TreeTest_01.GetBinTree();

    start_01 = clock();
    TreeTest_01.BFS_loop(pBinTree_01);
    finish_01 = clock();

    duration_01 = (double) (finish_01 - start_01);

    //////////////////////////////////////////////////////////////
    BinTree TreeTest_02;
    TreeTest_02.SetBinTree(num);

    clock_t start_02, finish_02;
    double duration_02;

    NodeStruct* pBinTree_02 = TreeTest_02.GetBinTree();
    queue<NodeStruct*> QueueOfNodes;
    QueueOfNodes.push(pBinTree_02);

    start_02 = clock();
    TreeTest_02.BFS_rec(QueueOfNodes);
    finish_02 = clock();

    duration_02 = (double) (finish_02 - start_02);


    cout << "time spent on recursive BFS : " << duration_01 << endl;
    cout << "time spent on loop BFS : " << duration_02 << endl;

    return 0;
}
