#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void test()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);

    sort(v.begin(), v.end(), greater<int>());

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    for_each(v.begin(), v.end(), [](int x)
             { cout << x << " "; });
}

void func()
{

}

struct Myfunc
{
    public:
        int n;
        Myfunc()
        {
            n = 0;
        }
        void operator()()
        {
            n++;
            cout << "n=" << n << endl;
        }
};

int main() 
{
    test();
    return 0;
}
