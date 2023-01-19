#include <stdio.h>

int Calc(int n, int *h, int *m)
{
	int i;
	*h = n % 10;
	n /= 10;
	while (n != 0)
	{
		*m = n % 10;
		n /= 10;
	}
	return n;
}

int main()
{
	int i, h, m, s;
	char flag;
	do
	{
		printf("\nEnter the int: ");
		scanf("%d", &i);
		if (i > 0)
		{
			Calc(i, &h, &m);
			printf("%d sol , %d sag ", m, h);
		}
		else
			printf("Bye");
	} while (i > 0);
	return 0;
}
