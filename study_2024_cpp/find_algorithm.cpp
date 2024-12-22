#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<numeric>
#include<functional>
#include<string.h>
using namespace std;

bool Myprint(int val)
{
    return val > 3;
}

void test()
{
    vector<int> v{ 1, 2, 3, 4, 5 };
    vector<int>::iterator it = find(v.begin(), v.end(), 3);
    if (it != v.end())
    {
        cout << "Found " << *it << endl;
    }else
    {
        cout << "Not found" << endl;
    }
    vector<int>::iterator it2 = find_if(v.begin(), v.end(), Myprint);
    if (it2 != v.end())
    {
        cout << "Found " << *it2 << endl;

    }else
    {
        cout << "Not found" << endl;
    }
    
}

class Maker
{
    public:
        string name;
        int age;
        Maker(string n, int a)
        {
            name = n;
            age = a;
        }
        bool operator==(const Maker& m) const
        {
            return name == m.name && age == m.age;
        }
        void print()
        {
            cout << "Name: " << name << " Age: " << age << endl;
        }
};

struct MyFind:public binary_function<Maker, Maker, bool>
{
    bool operator()(Maker m, Maker m2) const
    {
        return m.name == m2.name && m.age == m2.age;
    }
};

void test2()
{
    vector<Maker> makers{ {"John", 25}, {"Mary", 30}, {"Tom", 20} };
    vector<Maker>::iterator it = find(makers.begin(), makers.end(), Maker("Mary", 30));
    if (it != makers.end())
    {
        cout << "Found " << it->name << " Age: " << it->age <<endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    // vector<Maker>::iterator it2 = find_if(makers.begin(), makers.end(), [](Maker m){ return m.age < 25; });
    // if (it2 != makers.end())
    // {
    //     cout << "Found " << it2->name << " Age: " << it2->age << endl;
    // }
    // else
    // {
    //     cout << "Not found" << endl;
    // }
    vector<Maker>::iterator it3 = find_if(makers.begin(), makers.end(), bind2nd(MyFind(), Maker("John", 25))); 
    if (it3 != makers.end())
    {
        cout << "Found " << it3->name << " Age: " << it3->age << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
}

void test3()
{
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    bool flg=binary_search(v.begin(), v.end(), 5);
    if(flg)
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
    flg=binary_search(v.begin(), v.end(), 15);
    if(flg)
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
}

class Student
{
    public:
        string name;
        int age;
        Student(string n, int a)
        {
            name = n;
            age = a;
        }
};

void test4()
{
    vector<Student> students{ {"John", 25}, {"Mary", 30}, {"Tom", 20} };
    auto it = lower_bound(students.begin(), students.end(), Student("Mary", 30), [](Student s1, Student s2){return s1.name < s2.name;});
    if(it != students.end() && it->name == "Mary")
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
}

int main()
{
    test4();
    return 0;
}