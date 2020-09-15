// offer26.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL)
            return false;
        //
        return HasSubTree(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    bool HasSubTree(TreeNode* A, TreeNode* B)
    {
        //如果B走完了，说明匹配上了
        if (B == NULL)
            return true;
        //如果A走完了,B还没走完，
        if (A == NULL)
            return false;
        //节点不同，返回假
        if (A->val != B->val)
            return false;
        //当前节点相同，判断子节点。
        return HasSubTree(A->left, B->left) && HasSubTree(A->right, B->right);
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
