// offer36.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    //用pre指针指向上一个节点，head指针指向链表的头。
    //中序遍历时当需要输出当前节点时，改为修改节点的左右指针。
    //当pre节点为空时，说明当前遍历到的是第一个节点,用head指针保存。
    //遍历结束时pre指向链表尾节点
    Node* pre = NULL ;
    Node* head = NULL;
    Node* treeToDoublyList(Node* root) {
        if (root == NULL)
            return NULL;
        inorder(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
    void inorder(Node* cur)
    {
        if (cur == NULL)
            return;
        inorder(cur->left);
        if (pre == NULL)
            head = cur;
        else
        {
            pre->right = cur;
            cur->left = pre;
            
        }
        pre = cur;
        inorder(cur->right);
    }
};
void test()
{
    Node* head = new Node(4);
    head->left = new Node(2);
    //head->right = new Node(5);
    //head->left->left = new Node(1);
    //head->left->right = new Node(3);
    head = Solution().treeToDoublyList(head);
    while (head != NULL)
    {
        std::cout << head->val << "->";
        if (head->right == NULL)
            break;
        head = head->right;
    }
    std::cout << std::endl;
    while (head != NULL)
    {
        std::cout << head->val << "->";
        head = head->left;
    }
    std::cout << std::endl;
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
