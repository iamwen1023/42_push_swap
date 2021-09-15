/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:38:40 by wlo               #+#    #+#             */
/*   Updated: 2021/09/14 13:37:41 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_operation_2(char *line, t_listd **arr, t_listd **arr_b)
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
		return (1);
	return (0);
}

int	check_operation(char *line, t_listd **arr, t_listd **arr_b)
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
		return (check_operation_2(line, arr, arr_b));
	return (0);
}

void	free_arr(t_listd *arr, t_listd *arr_b)
{
	t_listd	*current;

	if (!arr && !arr_b)
		return ;
	while (arr)
	{
		current = arr;
		arr = arr->next;
		free(current);
	}
	while (arr_b)
	{
		current = arr_b;
		arr_b = arr_b->next;
		free(current);
	}
}

void	free_all(char *line, t_listd *arr, t_listd *arr_b)
{
	free(line);
	free_arr(arr, arr_b);
	error_exit();
}

int	main(int argc, char**argv)
{
	t_listd	*arr;
	char	*line;
	t_listd	*arr_b;

	arr_b = 0;
	if (argc == 1)
		return (0);
	if (check_error(argc, argv) == 1)
		error_exit();
	if (argc == 2)
		arr = parse_arg(argv[1]);
	else
		arr = parse_lst(argc, argv);
	while (get_next_line(0, &line) > 0)
	{
		if (check_operation(line, &arr, &arr_b) == 1)
			free_all(line, arr, arr_b);
		free(line);
	}
	if (confrim_sort(arr) == 1 && !arr_b)
		write(1, "OK\n", 3);
	else
		write(1, "K0\n", 3);
	free_arr(arr, arr_b);
	return (0);
}
