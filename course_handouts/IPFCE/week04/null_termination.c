#include "stdio.h"
int main(void)
{
    // string literals are implictly null terminated
    char null_terminated[22] = "I am null terminated!"; 

    char not_null_terminated[14] = {'n','o','t',' ','t','e','r','m','i','n','a','t','e','d'};

    
    printf("Printing null terminated string:\n");
    printf(null_terminated);

    printf("\nPrinting string with no null-termination:\n");
    printf(not_null_terminated);
    
    return 0;
}