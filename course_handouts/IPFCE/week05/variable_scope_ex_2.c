#include <stdio.h>   /* scanf, printf */

int x = 2;

int getx(int x)
{
    return x;
}

int main(void)
{
    int x;

    x = 1;

    x = getx(x);
    
    printf("%d\n", x);  /* prints: 1 */

    return 0;
}