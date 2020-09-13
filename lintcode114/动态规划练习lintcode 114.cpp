// 动态规划练习lintcode 114.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定m行n列的网格，有一个机器人从左上角(0,0)出发，每一步可以向下或者
//向右走一步，问有多少种不同的方式走到右下角


//走到最后一个格子f(3,7)=f(3,6)+f(2,7)
//状态方程 f(m,n)=f(m,n-1)+f(m-1,n);
//初始状态和边界情况f(0,0)=1,f(0,n)=f(m,0)=1
//
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //leetcode62：不同路径1
    int uniquePaths(int m, int n) {
        int **f = new int *[m];
        for (int i = 0; i < m; ++i)
            f[i] = new int[n];
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                f[i][j] = 1;
                if (i != 0 && j != 0)
                {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
    //leetcode63：不同路径2
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int** f = new int* [m];
        for (int i = 0; i < m; ++i)
            f[i] = new int[n];
        if (obstacleGrid[0][0] == 1)
            f[0][0] = 0;
        else
            f[0][0] = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {

                if (obstacleGrid[i][j] == 1)
                {
                    f[i][j] = 0;
                }
                else
                {
                    f[i][j] = 1;
                    if (i == 0&&j-1>=0)
                        f[i][j] = f[i][j-1];
                    if(j==0&&i-1>=0)
                        f[i][j] = f[i-1][j];
                    if (i != 0 && j != 0)
                    {
                        if (obstacleGrid[i][j] != 1)
                            f[i][j] = f[i - 1][j] + f[i][j - 1];
                    }
                }
                
            }
        }
        return f[m-1][n-1];
    }
    //leetcode55:跳跃游戏
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        //ai>=n-1-i 青蛙可以跳到石头i
        //状态：f[j]表示能不能跳到石头j
        int* f = new int[len];
        f[0] = 1;
        for (int i = 1; i < len; ++i)
        {
            f[i] = 0;
            for (int j = 0; j < i; ++j)
            {
                if (f[j] && (j + nums[j] >= i))
                {
                    f[i] = 1;
                    break;
                }
            }
        }
        if (f[len - 1] == 1)
        {
            return true;
        }
            
        else
        {   
            return false;
        }
        
    }
};
void test2()
{
    Solution s = Solution();
    //cout << s.uniquePaths(7, 3) << endl;

    vector<vector<int>> v;
    int m = 1, n = 2;
    v.resize(m);//行
    for (int i = 0; i < m; ++i)
    {
        v[i].resize(n);
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            v[i][j] = 0;

        }
    }
    v[0][0] = 1;
    cout << s.uniquePathsWithObstacles(v) << endl;
}

void test3()
{
    vector<int> v = { 2,3,1,1,4 };
    vector<int> v2 = { 3,2,1,0,4 };
    cout<<Solution().canJump(v)<<endl;
    cout << Solution().canJump(v2) << endl;
}
int main()
{
    test3();
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
