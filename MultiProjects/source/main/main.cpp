#include <iostream>
#include "add.h"
#include "sub.h"
int main()
{
    int a = 10, b = 5;
    int rt = add(a, b);
    rt = sub(a, b);
    return 0;
}