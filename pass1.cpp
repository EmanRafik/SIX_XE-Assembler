#include <iostream>
#include"Program.h"

using namespace std;

int main()
{
    Program* program= Program::getInstance();
    program->pass1();
    return 0;
}
