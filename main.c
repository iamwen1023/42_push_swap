//#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*s)
	{
		++length;
		s++;
	}
	return (length);
}

int	if_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	while (if_space(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	if (*str == '-' || *str == '+')
		return (0);
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		if (sign < 0 && result > 2147483648)
			return (0);
		if (sign > 0 && result > 2147483647)
			return (-1);
	}
	return (((int)result) * sign);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	if_numb(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[0] != '-' && ft_isdigit(s[0]) == 0)
			return (0);
		if (i > 0 && ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_error(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (1);
	i = 1;
	while (argv[i])
	{
		if (if_numb(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	if_repetive_num(int total, int *arry)
{
	int i;
	int	j;

	i = 1;
	while (i <= total)
	{
		j = i + 1;
		while (j <= total - 1)
		{
			if (arry[i] == arry[j])
				return (1);
			j++;
		}
		i++; 
	}
	return 0;
}

int main(int argc, char **argv)
{
	int	*arry;
	int	i;

	if (check_error(argc, argv) == 1)
	{
		write(1, "Error!\n", 7);
		return (1);
	}
	arry = malloc((argc - 1) * sizeof(int));
	if (!arry)
		return (1);
	i = 1;
	while (i < argc)
	{
		arry[i] = ft_atoi(argv[i]);
		i++;
	}
	if ((if_repetive_num(argc, arry) == 1))
	{
		printf("repeat\n");
		return (1);
	}
	if (argc < 6)
	{

	}
	printf("passs\n");

	return (0);
}