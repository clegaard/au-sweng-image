#include <stdio.h>
#include <stdlib.h>

int x; /* input value */
int y; /* output value */
int m; /* outer counter */
int n; /* inner counter */

int main (void) {
    scanf("%d", &x);
    
    if (x >= 0)
        ;
    else
        abort();

    m = 0;
    n = 0;
    y = 0;
    while (m < x)
    {
        while (n < x)
        {
            n += 1;
            y += 1;
        }
        n = 0;
        m += 1;
    }
    
    printf("%d\n", y);
}