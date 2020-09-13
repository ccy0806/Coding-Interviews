// Offer17.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include<string>
using namespace std;
class Solution {
public:
    //不考虑大数问题时：
    vector<int> printNumbers(int n) {
        vector<int> num_v;
        if (n <= 0)
            return num_v;
        int end = 1;
        for (int i = 0; i < n; ++i)
        {
            end *= 10;
        }
        for (int i = 1; i < end; ++i)
        {
            num_v.push_back(i);
        }
        return num_v;
    }
    //考虑大数问题时：
    vector<int> printNumbers2(int n)
    {
        vector<int> vec_Num;
        if (n <= 0)
            return vec_Num;
        //创建一个n+1位的字符数组存放数字
        string num = string(n , '0');
        n--;
        num[n]++;
        bool isOverFlow = false;
        while (!isOverFlow)
        {
            vec_Num.push_back(stoi(num));
            int bit_i = n;//记录当前进位到哪
            if(num[bit_i]=='9')
            { 
                while (bit_i>=0)//循环判断进位
                { 
                    if (num[bit_i] == '9')//9的时候准备进位
                    { 
                        num[bit_i] = '0';
                        bit_i--;
                        if (bit_i < 0)
                        {
                            isOverFlow = true;
                             break;
                        }                       
                    }
                    else//非9直接+1
                    {
                        num[bit_i]++;
                        break;
                    }

                }
            }
            else
                num[n]++;
            
        }
        return vec_Num;
    }

    //递归解法

    void pushStringInVec(string& num,vector<int>& vec, int n,int index)
    {
        if (n == index)
            return;
        for (int i = 0; i <10; ++i)
        {
            num[index] = '0' + i;  
            
            pushStringInVec(num, vec, n, index + 1);

            int temp = stoi(num);
            int vec_end = 0;
            if(!vec.empty())
            { 
                vec_end = *vec.rbegin();  
            }
            //递归过程不熟悉，里面有可能出现重复的数字。
            if(temp!=0&&temp!= vec_end)
                    vec.push_back(stoi(num));    
        }
    }
    vector<int> printNumbers3(int n)
    {
        vector<int>vec_Num;
        string num(n, '0');
        pushStringInVec(num,vec_Num, n,0);
        return vec_Num;
    }
    
   
};
int main()
{
    vector<int>v = Solution().printNumbers3(2);
    for (vector<int>::iterator it = v.begin(); it < v.end(); ++it)
    {
        cout << *it << " ";
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
