#include <stdio.h>   /* scanf, printf */

int x = 2;

int getx()
{
    return x;
}

int main(void)
{
    int x;

    x = 1;

    x = getx();
    
    printf("%d\n", x);  /* prints: 2 */

    return 0;
}