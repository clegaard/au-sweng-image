#include <stdio.h>   /* scanf, printf */
#include <malloc.h>   /* calloc */

int length(char s[])
{
    int len;
    for (len = 0; s[len] != 0; len = len + 1)
        ; /* do nothing! */
    return len;
}

int main(void)
{
    char *s;
    int len;
    
    s = (char*) calloc(80, sizeof(char));
    
    scanf("%s", s);
    
    len = length(s);
    
    printf("%d\n", len);
    
    return 0;
}