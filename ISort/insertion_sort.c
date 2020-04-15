#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX_ARRAY_SIZE = 50;

void insertion_sort (int a[], int n)
{
	for (int i =1; i < n; ++i)
	{
		int j = i;
		while (j > 0 && a[j - 1] > a [j])
		{
			int tmp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = tmp;

			--j;
		}
	}
}

int main ()
{
	srand(time(0));

	printf("before sorting:\n");
	int a[MAX_ARRAY_SIZE];
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		a[i] = rand() % 100;
		(i < (MAX_ARRAY_SIZE - 1)) ? printf("%d ", a[i]) : printf("%d \n", a[i]);
	}

	insertion_sort(a, MAX_ARRAY_SIZE);

	printf("after sorting:\n");
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		(i < (MAX_ARRAY_SIZE - 1)) ? printf("%d ", a[i]) : printf("%d \n", a[i]);
	}

	return 0;
}