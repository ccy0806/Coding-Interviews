// offer38.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> vec;
    vector<string> permutation(string s) {
        if (s == "")
            return vec;
        Permutation(0, s);
        return vec;
    }
    void Permutation(int index, string s)
    {
        if (index == s.length()-1)
        {
            vec.push_back(s);
        }
        for (int i = index; i < s.length(); ++i)
        {   
            if(judge(index, i ,s))continue;
            swap(s[index], s[i]);
            Permutation(index + 1, s);
            //swap(s[index], s[i]);
        }
  

    }
    void swapChar(int i, int j, string& s)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    bool judge(int start, int end, string s)
    {
        for (int i = start; i < end; ++i)
        {
            if (s[i] == s[end])
                return true;
        }
        return false;
    }
};
void test()
{
    string s = "abc";
    vector<string>v;
    v = Solution().permutation(s);
    for (auto i = v.begin(); i < v.end(); ++i)
    {
        cout << *i << endl;
    }
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
