#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;

//加入算法的回调
void MyPrint(int val)
{
    cout << val << " ";
}

void test() 
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    vector<int>::iterator begin = v.begin();
    vector<int>::iterator end = v.end();
    for_each(begin,end,MyPrint);
    cout << endl;
}

//容器储存对象
class Maker
{
    public:
    string name;
    int age;
    Maker(string name, int age) 
    {
        this->name = name;
        this->age = age;
    }
};
ostream& operator<<(ostream& os, const Maker& m)
{
    os << m.name << " " << m.age;
    return os;
}
void test2() 
{
    vector<Maker> makers;
    makers.push_back(Maker("Tom", 25));
    makers.push_back(Maker("Jerry", 30));
    makers.push_back(Maker("Mike", 20));
    makers.push_back(Maker("Lucy", 28));
    vector<Maker>::iterator begin = makers.begin();
    vector<Maker>::iterator end = makers.end();
    while(begin!= end)
    {
        // cout << begin->name << " " << begin->age << endl;
        // begin++;
        cout << (*begin)<<"  ";
        begin++;
    }
}
void test3() 
{
    vector<Maker*> makers;
    Maker *m1 = new Maker("Tom", 25);
    Maker *m2 = new Maker("Jerry", 30);
    Maker *m3 = new Maker("Mike", 20);
    Maker *m4 = new Maker("Lucy", 28);
    makers.push_back(m1);
    makers.push_back(m2);
    makers.push_back(m3);
    makers.push_back(m4);
    vector<Maker*>::iterator begin = makers.begin();
    vector<Maker*>::iterator end = makers.end();
    while(begin!= end)
    {
        // cout << begin->name << " " << begin->age << endl;
        // begin++;
        cout << (*begin)->name<<"  "<<(*begin)->age<<endl;
        begin++;
    }
    delete m1;
    delete m2;
    delete m3;
    delete m4;
}
//容器嵌套容器
void test4() 
{
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    vector<int> v5;
    for(int i=0;i<5;i++)
    {
        v1.push_back(i);
        v2.push_back(i+10);
        v3.push_back(i+20);
        v4.push_back(i+30);
        v5.push_back(i+40);
    }
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    // vector<vector<int>>::iterator begin = v.begin();
    // vector<vector<int>>::iterator end = v.end();
    // while(begin!= end)
    // {
    //     vector<int>::iterator it_begin = begin->begin();
    //     vector<int>::iterator it_end = begin->end();
    //     while(it_begin!= it_end)
    //     {
    //         cout << *it_begin << " ";
    //         it_begin++;
    //     }
    //     cout << endl;
    //     begin++;    
    // }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    test4();
    system("pause");
    return 0;
}