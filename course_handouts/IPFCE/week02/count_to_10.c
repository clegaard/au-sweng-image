#include <stdio.h>

int x;

int main (void)
{
	x = 1;
	printf("Initially x = %d\n", x);
	while (x < 10)
	{
		printf("%d < 10, ", x);
		x = x + 1;
		printf("x becomes %d\n", x);
	}
	printf("Finally x = %d\n", x);
}

/*

Initially x = 1
1 < 10, x becomes 2
2 < 10, x becomes 3
3 < 10, x becomes 4
4 < 10, x becomes 5
5 < 10, x becomes 6
6 < 10, x becomes 7
7 < 10, x becomes 8
8 < 10, x becomes 9
9 < 10, x becomes 10
Finally x = 10

*/