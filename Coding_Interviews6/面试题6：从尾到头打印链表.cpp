// 面试题6：从尾到头打印链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<stack>
using namespace std;
struct ListNode
{
    int m_Value;
    ListNode* m_Next;
};
//遍历链表
void printList(ListNode* pHead)
{
    if (pHead == NULL)
        return;
    ListNode* pNode = pHead;
    while (pNode != NULL)
    {
        cout << pNode->m_Value << "->";
        pNode = pNode->m_Next;
    }
    cout << endl;
}
//从末尾添加节点
void AddToTail(ListNode **pHead,int value)
{
    ListNode *newNode = new ListNode();
    newNode->m_Value = value;
    newNode->m_Next = nullptr;
    if (*pHead == nullptr)
    {
        *pHead = newNode;
    }
    else
    {
        ListNode* pNode = *pHead;
        while (pNode->m_Next != nullptr)
        {
            pNode = pNode->m_Next;
        }
        pNode->m_Next = newNode;
    }
}
//删除第一个某值的节点。
void RemoveNodeOnce(ListNode **pHead,int value)
{
    if (*pHead == NULL)
        return;
    ListNode* pNode = *pHead;
    if (pNode->m_Value == value)
    {
        *pHead = pNode->m_Next;
        delete pNode;
        return;
    }
    else
    {
        ListNode* pNextNode = (*pHead)->m_Next;
        while (pNextNode->m_Value!=value&&pNextNode->m_Next!=NULL)
        {
            pNextNode = pNextNode->m_Next;
            pNode = pNode->m_Next;
        }
        if (pNextNode->m_Value == value)
        {  
            pNextNode = pNextNode->m_Next;
            delete pNode->m_Next;
            pNode->m_Next = pNextNode;
            return;
        }
    }
}

void test()
{
    ListNode* pHead = NULL;
    AddToTail(&pHead, 2);
    AddToTail(&pHead, 5);
    AddToTail(&pHead, 1);
    printList(pHead);
    RemoveNodeOnce(&pHead, 2);
    printList(pHead);
    RemoveNodeOnce(&pHead, 5);
    printList(pHead);
    RemoveNodeOnce(&pHead, 1);
    printList(pHead);
}
void PrintListRevers(ListNode* pHead)
{
    stack<int> stk;
    if (pHead == NULL)
        return;
    ListNode* pNode = pHead;
    while (pNode != NULL)
    {
        stk.push(pNode->m_Value);
        pNode = pNode->m_Next;
    }
    while (!stk.empty())
    {
        cout <<  stk.top()<< " ";
        stk.pop();
    }
    cout << endl;
}
void test2()
{
    ListNode* pHead = NULL;
    AddToTail(&pHead, 2);
    AddToTail(&pHead, 5);
    AddToTail(&pHead, 1);
    printList(pHead);
    PrintListRevers(pHead);
}
int main()
{
    test2();

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
