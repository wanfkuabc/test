#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<functional>
using namespace std;

//第一步：继承
struct Myfunc:public binary_function<int,int,void>
{
    public:
    void operator()(int x,int y)const
    {
        cout << x+y << " ";
    }
};
void test()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);
    sort(v.begin(), v.end(), greater<int>());

    for_each(v.begin(), v.end(), bind2nd(Myfunc(), 100));
}

int main()
{
    test();
    return 0;
}