#include <stdio.h>   /* scanf, printf */

int main(void)
{
    int x; 
    
    x = 0;
        
    {
        int y;
        {
            int x;
            x = y + 1;
            
        }
        y = x + 1;
        x = y;
    }
    
    printf("%d\n", x);  /* prints: 1 */

    return 0;
}