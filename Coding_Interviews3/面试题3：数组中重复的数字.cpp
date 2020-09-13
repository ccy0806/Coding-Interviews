// 面试题3：数组中重复的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//在一个长度为n的数组里所有数字都在0~n-`的范围内。其中某些数字是重复的，但不知道有几个数字重复了，也不知道重复了几次
//请找出任意一个重复的数字。例如，{2,3,1,0,2,5,3},结果为2和3

//考虑了空指针驶入
//没考虑小于0或者大于n-1的数
#include <iostream>
using namespace std;


bool solve(int arr[],int len)
{
    if(arr==nullptr||len<=0)
    {
        return false;
    }
    for (int i = 0; i < len; i++)
    {
        while (arr[i] != i)
        {
            if (arr[i] == arr[arr[i]])
            {
                cout << arr[i] << endl;
                return true;
            }
            int temp_val = arr[i];
            arr[i] = arr[temp_val];
            arr[temp_val] = temp_val;
        }
    }
    return false;
}

void test()
{
    int num[10] = { 1,3,0,3,3,1,1,1,1,1 };
    solve(num,10);

}

void test2()
{
    int * num = nullptr;
    solve(num, 10);
}
void test3()
{
    int num[10] = { 1,2,3,4,5,6,7,4,9,0 };
    solve(num, 10);
}
int main()
{
    //test();
    //test2();
    test3();
    return 0;
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
