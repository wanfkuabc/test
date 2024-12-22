using namespace std;
#include <iostream>
#include <string.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

template<class NameType, class AgeType>
class Maker;
template <class NameType, class AgeType>
void printMaker(Maker<NameType, AgeType> &m);
template<class NameType, class AgeType>
class Maker
{
    friend void printMaker<>(Maker<NameType, AgeType> &p);

public:
    NameType name;
    AgeType age;

    Maker(NameType n, AgeType a)
    {   
        name = n;
        age = a;
    }
};
template<class NameType, class AgeType>
void printMaker(Maker<NameType, AgeType>& m)
{
    cout << "Name: " << m.name << endl;
    cout << "Age: " << m.age << endl;
}
void test()
{
    Maker<string, int> m("tom", 25);
    printMaker(m);
}
int main()
{
    test();
    return 0;
}