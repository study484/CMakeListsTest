#include "add.h"

int add_lib_shared_EXPORTS add(int a, int b)
{
    int *p = nullptr;
    *p = 5;
    return a + b;
}