/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:51:20 by wlo               #+#    #+#             */
/*   Updated: 2021/09/20 12:16:30 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_arr(t_listd *arr)
{
	t_listd	*current;

	if (!arr)
		return ;
	while (arr)
	{
		current = arr;
		arr = arr->next;
		free(current);
		current = NULL;
	}
}

int	count_n(t_listd	*arr)
{
	int	i;

	i = 0;
	while (arr)
	{
		i++;
		arr = arr->next;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_listd	*arr;
	int		n;

	if (check_error(argc, argv) == 1)
		error_exit();
	if (argc == 2)
		arr = parse_arg(argv[1]);
	else
		arr = parse_lst(argc, argv);
	n = count_n(arr);
	if (confrim_sort(arr) == 1)
	{
		free_arr(arr);
		return (0);
	}
	if (arr && n < 4)
		small_sort_3(&arr, arr);
	else if (n < 6)
		small_sort_5(&arr);
	else
		radix_sort(&arr, n);
	free_arr(arr);
	return (0);
}
