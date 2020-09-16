// offer32.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};
class Solution {
public:
    //队列实现层序遍历。
    vector<int> levelOrder(TreeNode* root) {
        vector<int> vec;
        if (root == NULL)
            return vec;
        queue<TreeNode*> list;
        list.push(root);
        while (!list.empty())
        {
            if (list.front() != NULL)
            {  
                if(list.front()->left)
                    list.push(list.front()->left);
                if(list.front()->right)
                    list.push(list.front()->right);
                vec.push_back(list.front()->val);
            }
            list.pop();
        }
        return vec;
    }
    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<int> v;
        vector<vector<int>> vec;
        if (root == NULL)
            return vec;
        queue<TreeNode*> list;
        list.push(root);
        int nextLevel = 0;
        int toBePrint = 1;
        int lvl = 0;
        while (!list.empty())
        {

            if (list.front() != NULL)
            {
                if (list.front()->left)
                { 
                    list.push(list.front()->left);
                    ++nextLevel;
                }
                if (list.front()->right)
                {
                    list.push(list.front()->right); 
                    ++nextLevel;
                }
                v.push_back(list.front()->val);
                --toBePrint;
            }
            list.pop();
            if (toBePrint == 0)
            {
                ++lvl;
                toBePrint = nextLevel;
                nextLevel = 0;
                vec.push_back(v);
                v.clear();
            }
        }
        return vec;
    }
    //队列加栈实现之字形输出，栈用来输出偶数行的节点，队列用来遍历和存储。
    vector<vector<int>> levelOrder3(TreeNode* root) {
        vector<int> v;
        vector<vector<int>> vec;
        if (root == NULL)
            return vec;
        queue<TreeNode*> list;
        stack<int> stk;
        list.push(root);
        int nextLevel = 0;//记录下一层有几个
        int toBePrint = 1;//记录这一层还需要打印几个
        int lvl = 0;//记录在第几层
        
        while (!list.empty() || !stk.empty())
        {
            if (list.front() != NULL)
            {
                if (list.front()->left)
                {
                    list.push(list.front()->left);
                    ++nextLevel;
                }
                if (list.front()->right)
                {
                    list.push(list.front()->right);
                    ++nextLevel;
                }
                if (lvl % 2 == 1)
                { 
                    stk.push(list.front()->val);
                }
                    
                else
                {
                    v.push_back(list.front()->val);
                }
                
                list.pop();
                --toBePrint;
            }
            if (toBePrint == 0)
            {
                while (!stk.empty())
                {
                    v.push_back(stk.top());
                    stk.pop();
                }
                ++lvl;
                toBePrint = nextLevel;
                nextLevel = 0;
                vec.push_back(v);
                v.clear();
            }
        }
        return vec;
    }
};
void test()
{
    
        TreeNode* head = new TreeNode(3);
        head->left = new TreeNode(9);
        head->right = new TreeNode(20);
        head->right->left = new TreeNode(15);
        head->right->right = new TreeNode(7);
        vector<vector<int>> v = Solution().levelOrder3(head);
        for (int i = 0; i < v.len(); ++i)
        {
            for (int j = 0; j < v[0].size(); ++j)
            {
                cout << v[i][j] << " ";
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
