// offer28.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//对称二叉树
//一个使用前序遍历 中左右，一个使用对称前序遍历即 中右左 两个指针同时遍历。
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return isSymmetrical(root, root);
    }
    bool isSymmetrical(TreeNode* head1, TreeNode* head2)
    {
        if (head1 == NULL && head2 == NULL)
            return true;
        if (head1 == NULL || head2 == NULL)
            return false;
        if (head1->val != head2->val)
            return false;
        //head1前序，head2对称前序
        return isSymmetrical(head1->left, head2->right) && isSymmetrical(head1->right, head2->left);
    }
};
int main()
{
    std::cout << "Hello World!\n";
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
