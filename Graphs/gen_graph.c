#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int n = 10;
	int array[n][n];

	FILE* fp = fopen("graph.txt", "r");
	if (!fp)
	{
		perror("Could not open graph.txt");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf(fp, "%d", &array[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("[");
		for (int j = 0; j < n; j++)
		{
			if (array[i][j] == 1)
			{
				printf("#");
			}
			else if (array[i][j] == 0)
			{
				printf(" ");
			}
		}
		printf("]\n");
	}

	fclose(fp);

	return 0;
}
