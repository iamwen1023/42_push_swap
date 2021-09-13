/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:34:10 by wlo               #+#    #+#             */
/*   Updated: 2021/09/13 18:32:59 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	if_num(char *s)
{
	int	i;

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
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j + 1 < size)
		{
			if (arry[i] == arry[j + 1])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_arg(char *argv)
{
	char	**num_list;
	int		i;
	int 	total;
	int		*arr;

	if (!ft_strcmp(argv, ""))
		error_exit();
	num_list = ft_split(argv, ' ');
	total = -1;
	while (num_list[++total])
	{
		if (if_num(num_list[total]) == 0)
			error_exit();
	}
	arr = (int *)malloc((total) * sizeof(int));
	if (!arr)
		return (1);
	i = -1;
	while (++i < total)
		arr[i] = ft_atoi(num_list[i]);
	i = -1;
	while (++i < total)
		free(num_list[i]);
	free(num_list);
	if (if_repetive_num(arr, total))
	{
		free(arr);
		error_exit();
	}
	free(arr);
	return (total);
}

int	check_error(int ac, char **av)
{
	int	i;
	int	*arr;

	if (ac == 1 || (ac == 2 && ((if_num(av[1]) == 1) || check_arg(av[1]) >= 1)))
		return (0);
	if (ac == 2 && check_arg(av[1]) < 1)
		return (1);
	i = 0;
	while (++i < ac)
	{
		if (if_num(av[i]) == 0)
			return (1);
	}
	arr = (int *)malloc((ac - 1) * sizeof(int));
	if (!arr)
		return (1);
	i = -1;
	while (++i < ac - 1)
		arr[i] = ft_atoi(av[i + 1]);
	i = if_repetive_num(arr, ac - 1);
	free(arr);
	if (i == 1)
		return (1);
	return (0);
}