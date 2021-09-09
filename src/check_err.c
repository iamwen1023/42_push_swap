#include "../push_swap.h"

int	if_numb(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[0] != '-' && s[0] != '+' && ft_isdigit(s[0]) == 0)
			return (0);
		if (i > 0 && ft_isdigit(s[i]) == 0)
			return (0);
		if (s[0] == '-' || s[0] == '+')
		{
			if (!s[1])
				return (0);
		}
		i++;
	}
	return (1);
}

int	if_repetive_num(int *arry, int size)
{
	int i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j + 1 < size)
		{
			if (arry[i] == arry[j+1])
				return (1);
			j++;
		}
		i++; 
	}
	return 0;
}

int	check_error(int argc, char **argv)
{
	int	i;
	int *arr;

	if (argc == 1 || argc == 2)
		return (1);
	i = 0;
	while (argv[++i])
	{
		if (if_numb(argv[i]) == 0)
			return (1);
	}
	arr = (int*)malloc((argc - 1) * sizeof(int));
	if (!arr)
		return (1);
	i = -1;
	while (++i < argc - 1)
		arr[i] = ft_atoi(argv[i + 1]);
	return (if_repetive_num(arr, argc - 1)? 1: 0);
}

void	error_exit(void)
{
	ft_putstr_fd("error\n", 1);
	exit(1);
}
