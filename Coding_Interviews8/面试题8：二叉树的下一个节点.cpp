// 面试题8：二叉树的下一个节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#include<vector>
struct BinaryTreeNode 
{
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pFather;
    char m_Value;
    BinaryTreeNode()
    {
        m_Value = ' ';
        m_pLeft = nullptr;
        m_pRight = nullptr;
        m_pFather = nullptr;
    }
    BinaryTreeNode(char value)
    {
        m_Value = value;
        m_pLeft = nullptr;
        m_pRight = nullptr;
        m_pFather = nullptr;
    }
};
BinaryTreeNode* FindInorderNext(BinaryTreeNode* pHead, BinaryTreeNode* targetNode)
{
    BinaryTreeNode* pNode = NULL;
    //目标节点有右子树，则沿着右子树走到最左下方的节点就是下一个节点
    if (targetNode->m_pRight != nullptr)
    {
        pNode = targetNode->m_pRight;
        while (pNode->m_pLeft != nullptr)
        {
            pNode = pNode->m_pLeft;
        }
        return pNode;
    }
    //目标节点没有右子树
    else
    {
        pNode = targetNode;
        //如果该节点是父节点的右儿子，则向父节点寻找，直到找到一个节点是父节点的左儿子，那么该父节点就是下一个节点；
        while (pNode == pNode->m_pFather->m_pRight)
        {
            pNode = pNode->m_pFather;
            //如果找到根节点，说明该节点为最后一个节点
            if (pNode == pHead)
            {
                return NULL;
            }
        }
        //如果该节点是父节点的左儿子，则父节点就是下一个节点；
        if (pNode == pNode->m_pFather->m_pLeft)
        {
            return pNode->m_pFather;
        }
        

        
    }
    
    
    
    return pNode;
}
void ConnectTreeNode(BinaryTreeNode* pFather, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if (pFather != nullptr)
    {
        pFather->m_pLeft = pLeft;
        pFather->m_pRight = pRight;
        if(pLeft!=nullptr)
            pLeft->m_pFather = pFather;
        if (pRight != nullptr)
            pRight->m_pFather = pFather;
    }
}
vector<BinaryTreeNode*> InitialTree(char *str)
{
    vector<BinaryTreeNode*> v;

    for(int i=0;i<strlen(str);i++)
    { 
        BinaryTreeNode* pNode = new BinaryTreeNode(str[i]);
        v.push_back(pNode);
    }
    //    a
    //   / \
    //  b   c
    // /\   /\
    //d  e f  g
    //  /\
    // h  i
    //测试1
    //ConnectTreeNode(v[0], v[1], v[2]);
    //ConnectTreeNode(v[1], v[3], v[4]);
    //ConnectTreeNode(v[2], v[5], v[6]);
    //ConnectTreeNode(v[4], v[7], v[8]);

    //测试2
    ConnectTreeNode(v[0], nullptr, v[2]);
    ConnectTreeNode(v[2], nullptr, v[6]);


    return v;
}
void InOrderPrintTree(BinaryTreeNode* pHead)
{
    if (pHead != nullptr)
    {
        if(pHead->m_pLeft!=nullptr)
            InOrderPrintTree(pHead->m_pLeft);
        cout << pHead->m_Value << ",";
        if(pHead->m_pRight!=nullptr)
            InOrderPrintTree(pHead->m_pRight);
    }
}
void test1()
{
    char str[10] = "abcdefghi";
    vector<BinaryTreeNode*> v;
    v= InitialTree(str);
    InOrderPrintTree(v[0]);
    cout << endl;
    BinaryTreeNode* pNode = FindInorderNext(v[0], v[2]);
    if(pNode!=NULL)
        cout <<v[2]->m_Value<<"的下一个是"<< pNode->m_Value << endl;
    else
    {
        cout << "该节点为最后一个节点" << endl;
    }
}
int main()
{
    test1();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
