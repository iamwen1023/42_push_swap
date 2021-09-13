#include "push_swap.h"

t_listd	*parse_lst(int argc, char **argv)
{
	int		i;
	t_listd	*temp;
	t_listd	*arr;

	i = 1;
	temp = 0;
	arr = 0;
	while (i < argc)
	{
		(temp) = ft_lstnew_doubly(ft_atoi(argv[i]));
		ft_lstadd_back_doubly(&arr, temp);
		i++;
	}
	replace_by_ranking(&arr, argc, argv);
	return (arr);
}

t_listd	*parse_arg(char *argv)
{
	char	**num_list;
	t_listd	*temp;
	t_listd	*arr;
	int		i;
	int		total;

	temp = 0;
	arr = 0;
	num_list = ft_split(argv, ' ');
	total = -1;
	while (num_list[++total])
	i = 0;
	while (i < total)
	{
		(temp) = ft_lstnew_doubly(ft_atoi(num_list[i]));
		ft_lstadd_back_doubly(&arr, temp);
		i++;
	}
	i = -1;
	replace_by_ranking_arg(&arr, total, num_list);
	while (++i < total)
		free(num_list[i]);
	free(num_list);
	return (arr);
}

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}