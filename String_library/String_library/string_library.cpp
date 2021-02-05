#include "string_library.h"

int ft_atoi_base(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			return (16);	//hex
		i++;
	}
	return (10);	//dec
}

int ft_atoi(char *str)
{
	int base;
	int minus = 1;
	int i = 0;
	int res = 0;

	if (!str)
		return (0);
	base = ft_atoi_base(str);
	while (str[i] == '-')
	{
		minus *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z'))
	{
		res *= base;
		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - '0';
		else
			res += str[i] - 'A' + 10;
		i++;
	}
	return (minus * res);
}

int	get_size(int num)
{
	int size = 0;
	long long n;

	if (num < 0 || num == 0)
		size++;
	if (num < 0)
		n = -num;
	else
		n = num;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char *ft_itoa(int num)
{
	char *str;
	long long n;
	int minus = 0;
	int size = get_size(num);
	int i = 0;

	str = (char *)malloc(size + 1);
	if (num < 0)
	{
		n = -num;
		str[0] = '-';
		i++;
	}
	else
		n = num;
	str[size] = '\0';
	while (i < size)
	{
		str[--size] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}

size_t	ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_strcpy(char *dest, char *src)
{
	int i = 0;

	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (-s2[i]);
	else if (!s2)
		return (s1[i]);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

