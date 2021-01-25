#include <iostream>
#include "add.h"
#include "sub.h"
#include "CCreateDump.h"
int main()
{
    CCreateDump::Instance()->DeclarDumpFile("test");
    int a = 10, b = 5;
    int rt = add(a, b);
    rt = sub(a, b);
    return 0;
}