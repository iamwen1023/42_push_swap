/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:51:20 by wlo               #+#    #+#             */
/*   Updated: 2021/09/13 10:23:09 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(t_listd **arr)
{
	t_listd	*current;

	if (!arr)
		return ;
	current = (*arr)->next;
	while (current->next)
	{
		free(*arr);
		arr = &current;
		current = current->next;
	}
	free(*arr);
}

int	main(int argc, char **argv)
{
	t_listd	*arr;

	if (check_error(argc, argv) == 1)
		error_exit();
	arr = parse_lst(argc, argv);
	if (confrim_sort(arr) == 1)
		return (0);
	if (argc <= 4)
		small_sort_3(&arr, arr);
	else if (argc <= 6)
		small_sort_5(&arr);
	else
		radix_sort(&arr, argc - 1);
	free_arr(&arr);
	return (0);
}
