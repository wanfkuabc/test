#pragma once
#include <iostream>
using namespace std;
#include <string.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

template<class TypeName,class TypeAge>
class Maker
{
public:
    Maker(TypeName name, TypeAge age);
    void PrintMaker();
public:
        TypeName name;
        TypeAge age;
};

template <typename TypeName, typename TypeAge>
Maker<TypeName, TypeAge>::Maker(TypeName name, TypeAge age)
{
    this->name = name;
    this->age = age;
    cout << "构造函数" << endl;
}
template <typename TypeName, typename TypeAge>
void Maker<TypeName, TypeAge>::PrintMaker()
{
    cout << "Name: " << this->name << endl;
    cout << "Age: " << this->age << endl;
}
        