// offer37.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<queue>
#include<sstream>
#include<vector>
using namespace std;
struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if (root == NULL)
            return str;
        queue<TreeNode*> list;
        list.push(root);
        while (!list.empty())
        {
            if (list.front())
            {
                str.append(to_string(list.front()->val));
                str.append(",");
                list.push(list.front()->left);
                list.push(list.front()->right);
            }
            else
                str.append("null,");
            list.pop();
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;
        istringstream istr(data);
        string s;
        TreeNode* root = NULL;
        vector<TreeNode*> vec;
        while (getline(istr,s,','))
        {

            if (s == "null")
            {
                vec.push_back(nullptr);
            }
            else
            {
                vec.push_back(new TreeNode(stoi(s)));
            }
        }
        for (int i = 0,j = 1; j < vec.size(); ++i)
        {
            if (vec[i] == nullptr)continue;
            if (j < vec.size()) vec[i]->left = vec[j++];
            if (j < vec.size())vec[i]->right = vec[j++];
        }
        return vec[0];
    }
    

};
void test()
{
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->right->right = new TreeNode(5);
    head->right->left = new TreeNode(4);
    string s = Codec().serialize(head);
    cout << s << endl;
    Codec().deserialize(s);
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
