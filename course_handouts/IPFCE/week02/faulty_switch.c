#include <stdio.h>

int x;

int main(void)
{

	scanf("%d", &x);

	switch (x)
	{
	case 0:
	case 1:
		printf("invalid value\n");
	case 2:
	case 3:
		x = 6 / x;
	case 4:
		x = 12 / (6 - x);
	default:
		x = 0;
	}
	
	printf("%d\n", x);
}
