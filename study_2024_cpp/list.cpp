#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

bool myfunc(int val)
{
    return val>=300;
}

void printList(list<int> &mylist)
{
    for(list<int>::iterator it=mylist.begin(); it!=mylist.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test()
{
    list<int> Mylist;
    for(int i=1; i<=10; i++)
    {
        Mylist.push_back(i);
    }
    list<int> Mylist1(10, 6);
    list<int> Mylist2(++Mylist.begin(), --Mylist.end());
    printList(Mylist);
    printList(Mylist1);
    printList(Mylist2);
}
void test1()
{
    list<int> Mylist;
    Mylist.push_back(1);
    Mylist.push_back(2);
    Mylist.push_back(3);
    Mylist.push_back(4);
    Mylist.push_front(100);
    Mylist.push_front(200);
    Mylist.push_front(300);
    Mylist.push_front(400);

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    Mylist.insert(Mylist.begin(), v.begin(), v.end());
    printList(Mylist);

    Mylist.remove(3);
    printList(Mylist);
    Mylist.remove_if(myfunc);
    printList(Mylist);
}
int main()
{
    test1();
    return 0;
}