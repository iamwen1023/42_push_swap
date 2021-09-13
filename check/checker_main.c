/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:38:40 by wlo               #+#    #+#             */
/*   Updated: 2021/09/13 14:34:03 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_operation_2(char *line, t_listd **arr, t_listd **arr_b)
{
	if (!ft_strcmp(line, "rr"))
	{
		rotate_a_np(arr);
		rotate_b_np(arr_b);
	}
	else if (!ft_strcmp(line, "rra"))
		r_rotate_a_np(arr);
	else if (!ft_strcmp(line, "rrb"))
		r_rotate_b_np(arr_b);
	else if (!ft_strcmp(line, "rrr"))
	{
		r_rotate_a_np(arr);
		r_rotate_b_np(arr_b);
	}
	else
		error_exit();
}

void	check_operation(char *line, t_listd **arr, t_listd **arr_b)
{
	if (!line)
		error_exit();
	if (!ft_strcmp(line, "sa"))
		swap_a_np(arr);
	else if (!ft_strcmp(line, "sb"))
		swap_b_np(arr_b);
	else if (!ft_strcmp(line, "pa"))
		push_a_np(arr, arr_b);
	else if (!ft_strcmp(line, "pb"))
		push_b_np(arr, arr_b);
	else if (!ft_strcmp(line, "ra"))
		rotate_a_np(arr);
	else if (!ft_strcmp(line, "rb"))
		rotate_b_np(arr_b);
	else
		check_operation_2(line, arr, arr_b);
}

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
	}
}

int	main(int argc, char**argv)
{
	t_listd	*arr;
	char	*line;
	t_listd	*arr_b;

	arr_b = 0;
	if (check_error(argc, argv) == 1)
		error_exit();
	arr = parse_lst(argc, argv);
	while (get_next_line(0, &line) > 0)
	{
		check_operation(line, &arr, &arr_b);
		free(line);
	}
	free(line);
	if (confrim_sort(arr) == 1 && !arr_b)
		write(1, "OK\n", 3);
	else
		write(1, "K0\n", 3);
	free_arr(arr);
	return (0);
}
