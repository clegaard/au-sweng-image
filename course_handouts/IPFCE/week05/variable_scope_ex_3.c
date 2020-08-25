#include <stdio.h>   /* scanf, printf */

int y = 0;

int main(void)
{
    int x; /* all occurrences of x refer here */
    
    scanf("%d", &x);
    
    if (x < 0) 
    {
        int y;
        y = -x;
    }
    else
    {
        int y;
        y = x;
    }

    x = y;

    printf("%d\n", x);  /* prints: 0 */

    return 0;
}