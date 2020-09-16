// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size()==0 && popped.size() == 0)
            return true;
        if (pushed.size() == 0 || popped.size() == 0)
            return false;
        stack<int> stk;
        int i = 0, j = 0;
        //通过一个栈辅助模拟过程。注意初始空栈的情况。
        while (j<popped.size())
        {
            if (stk.empty())
            {
                stk.push(pushed[i++]);
            }
            if(stk.top() == popped[j])
            {
                stk.pop();
                j++;
            }
            else
            {
                if (i >= pushed.size())
                    return false;
                stk.push(pushed[i++]);
            }
        }
        return true;
    }
};
int main()
{
    vector<int> v1 = { 1,2,3,4,5 };
    vector<int>v2 = { 4,3,5,1,2 };
    bool flag =  Solution().validateStackSequences(v1, v2);
    cout << flag << endl;
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
