// offer21.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //解法1：双指针，时间复杂度O(n),空间O(1)
    //写法有瑕疵，比较次数过多了,指针移位可以改成while
    vector<int> exchange(vector<int>& nums) {
        if (nums.empty()||nums.size()==1)
            return nums;
        int left_P = 0;
        int right_P = nums.size()-1;
        while (left_P < right_P)
        {
            if ((nums[left_P] %2 == 0) && (nums[right_P] % 2 ==1))
            {
                int temp = nums[left_P];
                nums[left_P] = nums[right_P];
                nums[right_P] = temp;
            }
            if (nums[left_P] % 2 == 1)
                left_P++;
            if ((nums[right_P] %2 == 0))
                right_P--;
        }
        return nums;
    }
    vector<int> exchange2(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1)
            return nums;
        int left_P = 0;
        int right_P = nums.size() - 1;
        while (left_P < right_P)
        {
            while ((nums[left_P] % 2 == 1) && left_P < right_P)
                left_P++;
            while ((nums[right_P] % 2 == 0) && left_P < right_P)
                right_P--;
            if (left_P < right_P)
            {
                int temp = nums[left_P];
                nums[left_P] = nums[right_P];
                nums[right_P] = temp;
            }
        }
        return nums;
    }
};
int main()
{
    vector<int> v = { 2,16,3,5,13,1,16,1,12,18,11,8,11,11,5,1 };
    Solution().exchange(v);
    for (auto i = v.begin(); i < v.end(); ++i)
    {
        cout << *i << endl;
    }
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
