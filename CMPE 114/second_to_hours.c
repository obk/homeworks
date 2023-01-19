#include <stdio.h>

void Calc(int *s, int *h, int *m)
{
	*h = *s / 3600;
	*s -= 3600 * (*h);
	*m = *s / 60;
	*s -= 60 * (*m);
}

int main()
{
	int i, h, m, s;
	printf("Enter the sec: ");
	scanf("%d", &s);
	Calc(&s, &h, &m);
	printf("%d hours , %d min , %d sec", h, m, s);
	return 0;
}
