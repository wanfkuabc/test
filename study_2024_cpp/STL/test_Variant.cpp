#include<iostream>
#include<variant>
using namespace std;

enum VariantType
{
    Int,
    Double,
};
struct Variant
{
    VariantType type;
    int i;
    double d;
};

void print(Variant v)
{
    if (v.type == Int)
        cout << v.i << endl;
    else
        cout << v.d << endl;
}