#include <stdio.h>

int main()
{
	int test_c = 1;
	char map[8][8];
	char find[3];
	int size;

	while (test_c <= 10)
	{
		int res = 0;

		scanf("%d\n", &size);
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				scanf(" %c ", &map[i][j]);
		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j <= 8 - size; j++)
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
		printf("#%d %d\n", test_c, res);
		test_c++;
	}
}