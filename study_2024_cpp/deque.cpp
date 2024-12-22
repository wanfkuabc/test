#include <iostream>
#include <deque>
using namespace std;

void PrintDeque(const deque<int> &d)
{
    for(deque<int>::const_iterator it = d.begin(); it!= d.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test()
{
    int arr[] = {1, 2, 3, 4, 5};
    deque<int> d(arr, arr + 5);
    PrintDeque(d);
    deque<int> d2(10, 6);
    PrintDeque(d2);
}
void test2()
{
    int arr[] = {1, 2, 3, 4, 5};
    deque<int> d(arr, arr + sizeof(arr)/sizeof(arr[0]));
    PrintDeque(d);
    deque<int> d2;
    d2.assign(d.begin(), d.end());
    d2.push_back(100);
    PrintDeque(d2);
    cout<<"------------------------"<<endl;
    d.swap(d2);
    PrintDeque(d);
    PrintDeque(d2);
}
void test3()
{
    deque<int> d;
    
}
int main()
{
    test2();
    return 0;
}