#include <stdio.h>
#include "./inlcude/myhead.h"

int main()
{
    int a = 1000;
    int b = 8;
    printf("%f, %f, %f, %f\n", add(a, b), sub(a,b), mul(a,b), div(a,b));
    return 0;
}