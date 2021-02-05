#include <stdio.h>

int main()
{
	int test_c = 1;
	char map[100][100];
	int size;

	while (test_c <= 10)
	{
		int res = 0;

		scanf("%d\n", &test_c);
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
				scanf(" %c ", &map[i][j]);
		}

		size = 100;
		while (size > 0)
		{
			for (int i = 0; i < 100; i++)
			{
				for (int j = 0; j <= 100 - size; j++)
				{
					int k = 0;
					while (map[i][k + j] == map[i][(size - 1) + j - k])
					{
						k++;
						if (k == size - 1)
							break;
					}
					if (k == size - 1)
						res++;

					k = 0;
					while (map[k + j][i] == map[(size - 1) + j - k][i])
					{
						k++;
						if (k == size - 1)
							break;
					}
					if (k == size - 1)
						res++;
				}
			}
			if (res == 0)
				size--;
			else
				break;
		}
		printf("#%d %d\n", test_c, size);
		test_c++;
	}
}