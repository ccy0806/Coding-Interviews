// offer34.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //注意输入[1],sum=1和[[1];[2]]sum=1;
    //需要路径到达叶子节点
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> allPath;
        if (root == NULL)
            return allPath;
        vector<int> onePath;
        findPath(root, sum, onePath, allPath);
        return allPath;
    }
    void findPath(TreeNode* root, int sum , vector<int> &onePath , vector<vector<int>>&allPath)
    {
        if (root == NULL)
        {
            return;
        }
        onePath.push_back(root->val);
        sum -= root->val;
        findPath(root->left, sum, onePath, allPath);
        findPath(root->right, sum, onePath, allPath);
        //需要路径到达叶子节点，判断重点
        if (sum == 0 &&root->left==NULL&&root->right==NULL)
            allPath.push_back(onePath);
        onePath.pop_back();
        sum += root->val;
    }
};
void test()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
   // root->right = new TreeNode(8);
   // root->left->left = new TreeNode(11);
   // root->right->left = new TreeNode(13);
   // root->right->right = new TreeNode(4);
   // root->left->left->left = new TreeNode(7);
  //  root->left->left->right = new TreeNode(2);
   // root->right->right->left = new TreeNode(5);
   // root->right->right->right = new TreeNode(1);
    vector<vector<int>> v;
    v = Solution().pathSum(root, 1);
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
    cout << endl;
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
