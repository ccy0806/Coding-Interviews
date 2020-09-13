// 面试题9：用两个栈实现队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#include <exception>
#include<stack>

template<typename T>
class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;

};
template <typename T> 
CQueue<T>::CQueue(void)
{
}

template <typename T> 
CQueue<T>::~CQueue(void)
{
}
template<typename T>
void CQueue<T>::appendTail(const T& node)
{
    this->stack1.push(node);
}
template<typename T>
T CQueue<T>::deleteHead()
{
    if (stack1.empty()&&stack2.empty())
        throw new exception("队列为空");
    if (stack2.empty())
    {
        while (!(stack1.empty()))
        {
            T temp = stack1.top();
            stack1.pop();
            stack2.push(temp);
            
        }
    }

    T temp = stack2.top();
    stack2.pop();
    return temp;
}
void Test(char actual, char expected)
{
    if (actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}
int main()
{
    
    CQueue<char> queue;

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    Test(head, 'a');

    head = queue.deleteHead();
    Test(head, 'b');

    queue.appendTail('d');
    head = queue.deleteHead();
    Test(head, 'c');

    queue.appendTail('e');
    head = queue.deleteHead();
    Test(head, 'd');

    head = queue.deleteHead();
    Test(head, 'e');
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
