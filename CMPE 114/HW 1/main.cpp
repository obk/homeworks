#include <stdio.h>
void polynomial(int array[], int degree)
{
	int i, flag;
	flag = degree;
	printf("\n====================================================");
	printf("\nYour original polynomial is: ");
	for (i = 0; i < flag; i++)
	{
		printf("%dx^%d", array[i], degree);
		if (array[i + 1] > 0)
			printf("+");
		degree = degree - 1;
	}
	printf("%d \n", array[i]);
	printf("\n====================================================");
}

void find_derivative(int array[], int degree, int time)
{
	int i, j, k, l;
	k = degree;
	printf("\n====================================================");
	printf("\nYour polynomial after %d time(s) derivative: \n", time);
	if (time > degree)
		printf("0\nBye!\n");
	if (time <= degree)
	{
		printf("\t");
		for (i = 0; i < degree; i++)
		{
			l = k;
			for (j = 0; j < time; j++)
			{
				array[i] = array[i] * l;
				l--;
			}
			if (l > 0)
				printf("%dx^%d + ", array[i], l);
			k--;
		}
		printf("%d", array[degree - time]);
	}
	printf("\n====================================================\n");
}
int main()
{
	int i, degree, flag, time;
	printf("Enter the degree of polynomial equation(1-10):");
	scanf("%d", &degree);
	printf("\n====================================================");
	int array[degree];
	flag = degree;
	for (i = 0; i <= degree; i++)
	{
		printf("\nEnter the coefficient of x to the power %d: ", flag);
		scanf("%d", &array[i]);
		flag--;
	}
	polynomial(array, degree);
	printf("\nWhich degree of derivative you want to calculate? ");
	scanf("%d", &time);
	find_derivative(array, degree, time);
	system("pause");
	return 0;
}
