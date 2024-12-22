#include <iostream>
using namespace std;
#include <string.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#include"template_in_fidderent_file.hpp"

int main() {
    Maker<string, int> m("jerry", 25);
    m.PrintMaker();
    Maker<char*, int> m2("tom", 26);
    m2.PrintMaker();
    system("pause");
    return 0;
}