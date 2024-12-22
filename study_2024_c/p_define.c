#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void func1(int a,char b)
{
    printf("hello world01\n");
}
void func0()
{
    printf("hello world00\n");
}
void func2()
{
    printf("hello world02\n");
}
void func3()
{
    printf("hello world03\n");
}
void test01()
{
    //定义一个函数类型
    typedef void(FUNC_TYPE)(int a,char b);

    //定义一个函数指针变量
    FUNC_TYPE *pFunc = func1;

    //通过函数指针调用函数
    pFunc(10,'a');
}

void test02()
{
    //定义一个函数类型
    typedef void(*FUNC_TYPE)(int a,char b);

    //定义一个函数指针变量
    FUNC_TYPE pFunc = func1;

    //通过函数指针调用函数
    pFunc(10,'a');
}

void test03()
{
    //直接定义函数指针变量
    void(*pFunc)(int a,char b) = func1;

    //通过函数指针调用函数
    pFunc(10,'a');


}

void test04()
{
    void (*FUNC_ARRAY[3])();

    FUNC_ARRAY[0] = func0;
    FUNC_ARRAY[1] = func2;
    FUNC_ARRAY[2] = func3;
    for (int i = 0; i < 3; i++)
    {
        FUNC_ARRAY[i]();
    }
    
}
int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}