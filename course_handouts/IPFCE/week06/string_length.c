#include <stdio.h>   /* scanf, printf */

int length(char s[])
{
    int len;
    for (len = 0; s[len] != 0; len = len + 1)
        ; /* do nothing! */
    return len;
}

int main(void)
{
    char s[80];
    int len;
    
    scanf("%s", s);
    
    len = length(s);
    
    printf("%d\n", len);
    
    return 0;
}