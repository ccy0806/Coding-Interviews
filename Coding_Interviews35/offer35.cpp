// offer35.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    //双向映射，空间换时间
    //蠢了，一个哈希表就够了
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        unordered_map<Node*, Node*> NewToOldMap;
        unordered_map<Node*, Node*> OldToNewMap;
        Node* newHead = NULL;
        bool isHead = true;
        Node* prePoint = NULL;
        while (head != NULL)
        {
            Node* node = new Node(head->val);    
            if (isHead)
            {
                newHead = node;
                prePoint = node;
                isHead = false;
            }
            else
            {
                prePoint->next = node;
                prePoint = prePoint->next;
            }
            NewToOldMap[node] = head;
            OldToNewMap[head] = node;
            head = head->next;
        }
        Node* node = newHead;
        while (node != NULL)
        {
            node->random = OldToNewMap[NewToOldMap[node]->random];
            node = node->next;
        }
        return newHead;
    }
    //一个哈希表 时间O(n),空间O(n)
    Node* copyRandomList2(Node* head)
    {
        if (head == NULL)
            return NULL;
        unordered_map<Node*, Node*> OldToNewMap;
        Node* newHead = NULL;
        bool isHead = true;
        Node* prePoint = NULL;
        Node* root = head;
        while (head != NULL)
        {
            Node* node = new Node(head->val);
            if (isHead)
            {
                newHead = node;
                prePoint = node;
                isHead = false;
            }
            else
            {
                prePoint->next = node;
                prePoint = prePoint->next;
            }
            OldToNewMap[head] = node;
            head = head->next;
        }
        while (root != NULL)
        {
            OldToNewMap[root]->random = OldToNewMap[root->random];
            root = root->next;
        }
        return newHead;
    }
    //在原链表基础上修改
    //
    Node* copyRandomList3(Node* head)
    {
        if (head == NULL)
            return NULL;
        //第一步在每一个原始的节点后面插入一个复制的节点
        //A->B->C 变为 A->A'->B->B'->C->C'
        head = insertNewNode(head);
        outNode(head);
        //第二步设置random指针
        setRandomPoint(head);
        outNode(head);
        //第三步拆成两个链表
        head = rebuildNode(head);
        outNode(head);
        return head;
    }
    Node* insertNewNode(Node* head)
    {
        Node* node = head;
        while (node != NULL)
        {
            Node* cloneNode = new Node(node->val);
            if (node->next != NULL)
            {
                cloneNode->next = node->next;
                node->next = cloneNode;
            }
            else
            {
                node->next = cloneNode;
            }
            node = node->next->next;
        }
        return head;
    }
    void setRandomPoint(Node* head)
    {
        Node* root = head;
        Node* oriNode = head;
        Node* cloneNode = NULL;
        while (oriNode != NULL)
        {
            cloneNode = oriNode->next;
            if (oriNode->random != NULL)
                cloneNode->random = oriNode->random->next;
            oriNode = oriNode->next->next;
        }
    }
    Node* rebuildNode(Node* head)
    {
        Node* cloneNode = head->next;
        Node* oriNode = head;
        Node* cloneHead = cloneNode;
        Node* oriHead = oriNode;
        outNode(oriHead);
        outNode(cloneHead);
        int count = 0;
        head = head->next->next;
        if (head == NULL)
        {
            oriHead->next = NULL;
        }
        while (head != NULL)
        {
            if (count % 2 == 0)
            {
                oriNode->next = head;
                cloneNode->next = NULL;
                oriNode = oriNode->next;
            }
            else
            {
                cloneNode->next = head;
                oriNode->next = NULL;
                cloneNode = cloneNode->next;
            }
            head = head->next;
            count++;
        }
        return cloneHead;
    }
    void outNode(Node* head)
    {
        Node* root = head;
        while (root != NULL)
        {
            cout << &(*root)<< "->";
            root = root->next;
        }
        cout << endl;
    }
};
void test()
{
    Node* head = new Node(1);
    head->next = NULL;
   // head->next = new Node(2);
   // head->random = head->next;
   // head->next->next = NULL;
  //  head->next->random = head->next;
    Solution().copyRandomList3(head);
}
int main()
{
    test();
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
