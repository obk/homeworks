#include <stdio.h>
void Calc(int n, int *factorial)
{
	int i;
	*factorial = 1;
	for (i = 1; i <= n; i++)
		*factorial = *factorial * i;
}

int main()
{
	int i, factorial, n;
	char flag;
	printf("Enter a number: ");
	scanf("%d", &n);
	Calc(n, &factorial);
	printf("Factorial of %d is: %d", n, factorial);
	return 0;
}
