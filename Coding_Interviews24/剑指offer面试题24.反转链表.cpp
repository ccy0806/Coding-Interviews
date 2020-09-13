// 剑指offer面试题24.反转链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    //第一种思路:头插法建立新链表（需要建立新链表）
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* tail = NULL;

        while (head != NULL)
        {
            int temp_val = head->val;
            ListNode* node = new ListNode(temp_val);
            node->next = tail;
            tail = node;
            head = head->next;
        }
        ListNode* head2 = tail;
        while (head2 != NULL)
        {
            std::cout << head2->val << "->";
            head2 = head2->next;
        }
        std::cout << NULL << std::endl;
        return tail;
    }

    //第二种:双指针反转链表
    ListNode* reverseList2(ListNode* head)
    {
        if (head == NULL)
            return NULL;
        ListNode* pre = head;
        ListNode* curr = head->next;
        pre->next = NULL;
        while (curr != NULL)
        {
            ListNode* node = new ListNode(curr->val);
            node->next = pre;
            pre = node;
            curr = curr->next;
        }
        return pre;
    }

    //第三种:递归
    ListNode* reverseList3(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p = reverseList3(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};
int main()
{
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
