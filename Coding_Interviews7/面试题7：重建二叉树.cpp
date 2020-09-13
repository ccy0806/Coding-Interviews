// 面试题7：重建二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//根据前序遍历和中序遍历构建二叉树

#include <iostream>
#include<string>
using namespace std;
struct BinaryTreeNode
{
    int m_Value;
    BinaryTreeNode* m_pLeft; 
    BinaryTreeNode* m_pRight;
};
BinaryTreeNode* BuildTreeCore(int* PreOrderBegin, int* PreOrderEnd, int* InOrderBegin, int* InOrderEnd)
{

    BinaryTreeNode *Node = new BinaryTreeNode();
    int rootValue = PreOrderBegin[0];
    Node->m_Value = rootValue;
    Node->m_pLeft = NULL;
    Node->m_pRight = NULL;
    int offset = 0;
    while (*(InOrderBegin + offset) != rootValue)
    {
        if (InOrderBegin + offset > InOrderEnd)
        {
            cout << "序列有误" << endl;
            
            return Node;
        }
        offset++;
    }
    //防止前指针超越后指针
    if(PreOrderBegin + 1<= PreOrderBegin + offset&& InOrderBegin<= InOrderBegin + offset - 1)
        Node->m_pLeft = BuildTreeCore(PreOrderBegin + 1, PreOrderBegin + offset, InOrderBegin, InOrderBegin + offset - 1);
    if(PreOrderBegin + offset + 1<= PreOrderEnd&& InOrderBegin + offset + 1<= InOrderEnd)
        Node->m_pRight = BuildTreeCore(PreOrderBegin + offset + 1, PreOrderEnd, InOrderBegin + offset + 1, InOrderEnd);
    return Node;
}
BinaryTreeNode* BuildTree(int* PreOrder, int* InOrder,int len)
{
    if (PreOrder == nullptr || InOrder == nullptr || len <= 0)
        return NULL;
    return BuildTreeCore(PreOrder, PreOrder + len - 1, InOrder, InOrder + len - 1);
}
void PreOrderShowTree(BinaryTreeNode* pHead)
{
    if (pHead == NULL)
        return;
    cout << pHead->m_Value << " ";
    PreOrderShowTree(pHead->m_pLeft);
    PreOrderShowTree(pHead->m_pRight);
}
void InOrderShowTree(BinaryTreeNode* pHead)
{
    if (pHead == NULL)
        return;
    InOrderShowTree(pHead->m_pLeft);
    cout << pHead->m_Value << " ";
    InOrderShowTree(pHead->m_pRight);
}
void PostOrderShowTree(BinaryTreeNode* pHead)
{
    if (pHead == NULL)
        return;
    PostOrderShowTree(pHead->m_pLeft);
    PostOrderShowTree(pHead->m_pRight);
    cout << pHead->m_Value << " ";
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode* pHead = NULL;
    pHead = BuildTree(preorder, inorder, length);
    PreOrderShowTree(pHead);
    cout << endl;
    InOrderShowTree(pHead);
    cout << endl;
    PostOrderShowTree(pHead);
    cout << endl;
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};
    BinaryTreeNode* pHead = NULL;
    pHead = BuildTree(preorder, inorder, length);
    PreOrderShowTree(pHead);
    cout << endl;
    InOrderShowTree(pHead);
    cout << endl;
    PostOrderShowTree(pHead);
    cout << endl;
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};
    BinaryTreeNode* pHead = NULL;
    pHead = BuildTree(preorder, inorder, length);
    PreOrderShowTree(pHead);
    cout << endl;
    InOrderShowTree(pHead);
    cout << endl;
    PostOrderShowTree(pHead);
    cout << endl;
}

// 树中只有一个结点
void Test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};
    BinaryTreeNode* pHead = NULL;
    pHead = BuildTree(preorder, inorder, length);
    PreOrderShowTree(pHead);
    cout << endl;
    InOrderShowTree(pHead);
    cout << endl;
    PostOrderShowTree(pHead);
    cout << endl;
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 2, 6, 3, 7};
    BinaryTreeNode* pHead = NULL;
    pHead = BuildTree(preorder, inorder, length);
    PreOrderShowTree(pHead);
    cout << endl;
    InOrderShowTree(pHead);
    cout << endl;
    PostOrderShowTree(pHead);
    cout << endl;
}
int main()
{
    //Test1();
    //Test2();
    //Test3();
    //Test4();
    Test5();
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
