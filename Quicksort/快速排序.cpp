// 快速排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<exception>
#include<Random>
#include<time.h>
using namespace std;
int RandomInRange(int start, int end)
{
    
    return rand() % (end - start+1) + start;
}
void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int Partition(int arr[],int start,int end,int mode)
{
    if (end <= start || start < 0)
    {
        throw new exception("Invalid Parameters");
    }
    int index = RandomInRange(start, end);
    Swap(arr[index], arr[end]);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    switch (mode)
    {
    case -1:
    {        int big = start - 1;
        for (index = start; index < end; index++)
        {
            if (arr[index] > arr[end])
            {
                big++;
                if (big != index)
                    Swap(arr[index], arr[big]);
            }
        }
        big++;
        Swap(arr[big], arr[end]);
        return big;
        break;
    }

    default:
    { int small = start - 1;
        for (index = start; index < end; index++)
        {
            if (arr[index] < arr[end])
            {
                small++;
                if (small != index)
                    Swap(arr[index], arr[small]);
            }
        }
        small++;
        Swap(arr[small], arr[end]);
        return small;
        break;
    }
       
    }
   
}
void QuickSort(int arr[],int start,int end,int mode)
{
    if (start == end)
        return;
    int index = Partition(arr,start,end,mode);
    if (index > start)
        QuickSort(arr, start, index - 1,mode);
    if (index < end)
        QuickSort(arr, index + 1, end,mode);
}

int main()
{
    srand(time(NULL));
    int a[10] = { 1,2,22,23,21,2,2,32,2,6 };
    QuickSort(a, 0, 9,-1);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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
