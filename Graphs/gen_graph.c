#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int n = 10;
	int array[n][n];
	int count = 0;

	FILE* fp = fopen("graph.txt", "r");
	if (!fp)
	{
		perror("Could not open graph.txt");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; i++)
	{
		for (count = 0; count < n; count++)
		{
			fscanf(fp, "%d", &array[i][count]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("[");
		for (count = 0; count < n; count++)
		{
			if (array[i][count] == 1)
			{
				printf("#");
			}
			else if (array[i][count] == 0)
			{
				printf(" ");
			}
		}
		printf("]\n");
	}

	fclose(fp);

	return 0;
}
