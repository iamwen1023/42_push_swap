/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:38:40 by wlo               #+#    #+#             */
/*   Updated: 2021/09/20 15:30:04 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		current = NULL;
	}
	while (arr_b)
	{
		current = arr_b;
		arr_b = arr_b->next;
		free(current);
		current = NULL;
	}
}

void	free_all(char *line, t_listd *arr, t_listd *arr_b)
{
	free(line);
	free_arr(arr, arr_b);
	error_exit();
}

int	parse_func(int argc, char **argv, t_listd **arr)
{
	if (ft_strcmp(argv[1], "") == 0)
		error_exit();
	if (argv[1] && argc == 2)
		(*arr) = parse_arg(argv[1]);
	else
		(*arr) = parse_lst(argc, argv);
	if (*arr)
		return (1);
	return (0);
}

void	read_input(t_listd	**arr, t_listd	**arr_b)
{
	char	*line;
	int		ret;

	line = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (ret < 0)
			break ;
		if (check_operation(line, arr, arr_b) == 1)
			free_all(line, *arr, *arr_b);
		free(line);
		line = NULL;
	}
	if (ret == 0)
		free(line);
	else
	{
		free_all(line, *arr, *arr_b);
		error_exit();
	}
}

int	main(int argc, char**argv)
{
	t_listd	*arr;
	t_listd	*arr_b;

	arr_b = 0;
	if (argc == 1)
		return (0);
	if (check_error(argc, argv) == 1)
		error_exit();
	arr = 0;
	if (parse_func(argc, argv, &arr) == 0)
		return (0);
	read_input(&arr, &arr_b);
	if (confrim_sort(arr) == 1 && !arr_b)
		write(1, "OK\n", 3);
	else
		write(1, "K0\n", 3);
	free_arr(arr, arr_b);
	return (0);
}
