#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// typedef struct s_list 
// {
// 	int num;
// 	struct s_list *next;
// } t_list;

int	if_numb(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[0] != '-' && ft_isdigit(s[0]) == 0)
		{
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
		if (if_numb(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	if_repetive_num(int *arry)
{
	int i;
	int	j;

	i = 1;
	while (arry[i])
	{
		j = i;
		while (arry[j + 1])
		{
			printf("arry %d:%d\n", arry[i], arry[j+1]);
			if (arry[i] == arry[j+1])
				return (1);
			j++;
		}
		i++; 
	}
	return 0;
}
int quicksort(t_list *arr, int numb)
{
	int step;
	int	i;
	t_list arr2;

	step = 0;
	i = 1;
	while(i < numb)
	{
		if(arr[numb - 1]  < arr[i])
			{
				printf"pb\n");
			}
	}

	return 0;
}

int main(int argc, char **argv)
{
	int	*arry;
	int	i;
	t_list *arr;
	t_list *temp;

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
	arr = ft_lstnew(ft_atoi(argv[1]));
	i = 2;
	while (i < argc)
	{
		temp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&arr , temp);
		i++;
	}
	i = 1;
	temp = arr;
	while (i < argc)
	{
		printf("num : %d\n", temp->content);
		temp = temp->next;
		i++;
	}
	printf("passs\n");
	quicksort(arr, argc-1);

	return (0);
}