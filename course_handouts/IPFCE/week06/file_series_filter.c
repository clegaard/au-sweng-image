/*
 * Filter an increasing series of 
 * int numbers from file "series.txt" 
 * into the file "incseries.txt"
 */

#include <stdio.h>   /* scanf, printf */

int main(void)
{
    int x;
    int y;
    int ok;
    FILE *inp;
    FILE *outp;
    
    inp = fopen("series.txt", "r");
    outp = fopen("incseries.txt", "w");

    x = 0;
    for(ok = fscanf(inp, "%d", &y);
        ok == 1; 
        ok = fscanf(inp, "%d", &y))
        if (y > x)
        {
            fprintf(outp, "%d\n", y);
            x = y;
        }

    fclose(inp);
    fclose(outp);
    
    return 0;
}