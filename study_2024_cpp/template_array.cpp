using namespace std;
#include <iostream>
#include <string.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#include"template_array.hpp"
class Maker
{
    public:
    string name;
    int age;
    Maker()
    {

    }
    Maker(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

void printMaker(MyArray<Maker>& makerArray)
{
    for (int i = 0; i < makerArray.get_size(); i++)
    {
        cout << makerArray[i].name << " " << makerArray[i].age << endl;
    }

}
void test()
{
    MyArray<Maker> makerArray(5);
    Maker m1("tom", 25);
    Maker m2("jerry", 30);
    Maker m3("alice", 28);
    Maker m4("bob", 35);
    Maker m5("mary", 23);
    makerArray.push_back(m1);
    makerArray.push_back(m2);
    makerArray.push_back(m3);
    makerArray.push_back(m4);
    makerArray.push_back(m5);
    MyArray<int> intArray(5);
    for(int i=0;i<5;i++)
    {
        intArray.push_back(i+100);
    }
    for(int i=0;i<5;i++)
    {
        cout<<intArray[i]<<endl;
    }
    // for (int i = 0; i < makerArray.getSize(); i++)
    // {
    //     cout << makerArray[i].name << " " << makerArray[i].age << endl;
    // }
    printMaker(makerArray);
}

int main()
{
    test();
    system("pause");
    return 0;
}
