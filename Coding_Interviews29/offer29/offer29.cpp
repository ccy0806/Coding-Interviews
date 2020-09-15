// offer29.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//顺时针打印矩阵

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vec;
        if (matrix.empty())
            return vec ;
        int height = matrix.size();
        int width = matrix[0].size();
        int head = 0, tail = height - 1;
        int left = 0, right = width - 1;
        int count = height * width;
        while (head <= tail &&left<=right&&count>0)
        {
            //打印上面
            for (int i = left; i <= right; ++i)
            { 
                vec.push_back(matrix[head][i]);
                count--;
                //cout << matrix[head][i] << endl;     
            }
            if (head + 1 > tail)
                break;
            //打印右边
            for (int i = head + 1; i <= tail - 1; ++i)
            {
                vec.push_back(matrix[i][right]);
                count--;
                //cout << matrix[i][right] << endl;
            }
            //打印下面
            for (int i = right; i >= left; --i)
            {
                vec.push_back(matrix[tail][i]);
                count--;
               // cout << matrix[tail][i] << endl;
            }
            //打印左边
            for (int i = tail -1 ; i >= head + 1; --i)
            {
                if (count > 0)
                {
                    vec.push_back(matrix[i][left]);
                    count--;
                  //  cout << matrix[i][left] << endl;
                }
            }
            head++;
            tail--;
            left++;
            right--;
        }
        //cout << endl;
        return vec;
    } 
};
int main()
{
    int numRows = 2, zone = 3;//层数，每层需要的空间
    vector<vector<int>> vect(numRows, vector<int>());//初始层数，赋值
    for (int i = 0; i < numRows; i++) {
        vect[i].resize(zone);
    }
    int a = 1;
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < zone; ++j)
        {
            vect[i][j] = a++;
        }
    }
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < zone; ++j)
        {
            cout << vect[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl;
    Solution().spiralOrder(vect);
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
