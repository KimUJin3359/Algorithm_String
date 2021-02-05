
#include <stdio.h>

size_t   ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int main()
{
	int test_c = 0;
	char src[1024];
	char find[16];

	while (test_c <= 10)
	{
		int res = 0;
		int i = 0;
		int j;

		scanf("%d\n", &test_c);
		scanf("%s\n", find);
		scanf("%s\n", src);
		while (src[i])
		{
			j = 0;
			if (src[i + j] == find[j])
			{
				while (find[++j])
				{
					if (find[j] != src[i + j])
						break;
				}
			}
			if (j == ft_strlen(find))
				res++;
			i++;
		}
		printf("#%d %d\n", test_c, res);
		test_c++;
	}
}