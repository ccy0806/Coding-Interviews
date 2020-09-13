// 面试题1：赋值运算符函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#pragma warning(disable:4996)
#include <iostream>
using namespace std;

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);
    CMyString& operator=(const CMyString& str);
    void printt()
    {
        printf("%s\n", this->m_pData);
        
    }
private:
    char* m_pData;
};
CMyString::CMyString(char* pData)
{
    if (pData == nullptr)
    {
        this->m_pData = new char[1];
        m_pData[0] = '\n';
    }
    else
    {
        this->m_pData = new char[strlen(pData) + 1];
        strcpy(this->m_pData, pData);
    }
}
CMyString::CMyString(const CMyString& str)
{
    int len = strlen(str.m_pData);
    this->m_pData = new char[len + 1];
    strcpy(this->m_pData, str.m_pData);
}
CMyString::~CMyString(void)
{
    cout << "析构函数调用" << endl;
    if (this->m_pData != nullptr)
    {
        delete m_pData;
       // m_pData = NULL;
    }

   
}
//初级版，存在异常安全性问题
//CMyString& CMyString::operator=(const CMyString& str)
//{
//    if (this == &str)
//        return *this;
//    int len = strlen(str.m_pData);
//    delete[] m_pData;
//    m_pData = nullptr;
//    m_pData = new char[len + 1];
//    strcpy(m_pData, str.m_pData);
//    return *this;
//}

//高级版
CMyString& CMyString::operator=(const CMyString& str)
{
    if (this != &str)
    {
        //优点
        //1.strTemp是一个局部变量，因此在if结束后，会自动调用析构函数释放掉strTemp.m_pData指向的内存也就是原有的内存；
        //2.在生成对象strTemp调用构造函数时用new分配内存，若此时内存不足，我们还没有修改原有的实例。
        CMyString strTemp(str);
        
        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
}
void test1()
{
    char* p = (char*)"bilibili";
    CMyString A(p); 
    CMyString B(A);
    A.printt();
    B.printt();
}
void Test2()
{
    printf("Test2 begins:\n");

    char* text = (char*)"Hello world";

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.printt();
    printf(".\n");
}

// 连续赋值
void Test3()
{
    printf("Test3 begins:\n");

    char* text = (char*)"Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.printt();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.printt();
    printf(".\n");
}
int main()
{

    test1();
    Test2();
    Test3();
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
