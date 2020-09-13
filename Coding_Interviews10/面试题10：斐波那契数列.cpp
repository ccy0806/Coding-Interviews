// 面试题10：斐波那契数列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//用循环解决，保存每次计算的数；f0+f1=f2;记录f1,f2，计算f1+f2...

#include <iostream>
using namespace std;
long long Fibonacci(unsigned int n)
{
    int result[2] = { 0,1 };
    if (n <= 1)
    {
        return result[n];
    }
    long long val1 = 0;
    long long val2 = 1;
    long long value = 0;
    for (unsigned int i = 2; i <= n; i++)
    {
        value = val1 + val2;
        val1 = val2;
        val2 = value;
    }
    return value;
}
// ====================测试代码====================
void Test(int n, int expected)
{
    if (Fibonacci(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);

    if (Fibonacci(n) == expected)
        printf("Test for %d in solution2 passed.\n", n);
    else
        printf("Test for %d in solution2 failed.\n", n);

    if (Fibonacci(n) == expected)
        printf("Test for %d in solution3 passed.\n", n);
    else
        printf("Test for %d in solution3 failed.\n", n);
}
int main()
{
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);
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
