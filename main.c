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
		printf("s[i]:%c\n", s[i]);
		printf("len :%zu\n", ft_strlen(&s[i]));
		if (s[1] != '-' && ft_isdigit(s[1]) == 0)
		{
			printf("here?");
			return (0);
		}
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
		printf("arr: %s\n", argv[i]);
		if (if_numb(argv[i]) == 0)
		{
			printf("if_num: %d\n", if_numb(argv[i]));
			return (1);
		}
		i++;
	}
	return (0);
}

int	if_repetive_num(int *arry)
{
	int i;

	i = 0;
	while (arry[i + 1])
	{
		if (arry[i] == arry[i+1])
			return (1);
		i++; 
	}
	return 0;
}

int main(int argc, char **argv)
{
	int	*arry;
	int	i;

	//printf("if not :%d\n",ft_isdigit('8'));
	if (check_error(argc, argv) == 1)
	{
		write(1, "Error!\n", 7);
		return (1);
	}
	// arry = malloc((argc - 1) * sizeof(int));
	// if (!arry)
	// 	return (1);
	// i = 1;
	// while (i < argc)
	// {
	// 	arry[i] = ft_atoi(argv[i]);
	// 	i++;
	// }
	// if ((if_repetive_num(arry) == 1))
	// {
	// 	printf("repeat\n");
	// 	return (1);
	// }
	// if (argc < 6)
	// {

	// }
 

	return (0);
}