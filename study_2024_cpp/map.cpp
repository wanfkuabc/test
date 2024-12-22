#include <iostream>
#include <map>
using namespace std;
template<typename T>
void print(T &m)
{
    for(map<int, string>::iterator it = m.begin(); it!= m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;

    }
    cout << endl;
}
struct mapfunc
{
    bool operator()(int key1,int key2)
    {
        return key1>key2;
    }
};
void test()
{
    map<int, string, mapfunc> m;
    m.insert(pair<int, string>(1, "apple"));
    m.insert(pair<int, string>(5, "banana"));
    m.insert(pair<int, string>(6, "orange"));
    m.insert(pair<int, string>(4, "grape"));
    print(m);
}
int main()
{
    test();
    return 0;
}
