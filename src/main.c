/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:51:20 by wlo               #+#    #+#             */
/*   Updated: 2021/09/10 18:13:24 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_listd	*arr;

	if (check_error(argc, argv) == 1)
		error_exit();
	arr = parse_lst(argc, argv);
	print_out(arr);
	if (confrim_sort(arr) == 1)
		return (0);
	if (argc <= 4)
		small_sort_3(&arr, arr);
	else if (argc <= 6)
		small_sort_5(&arr);
	else
		radix_sort(&arr, argc - 1);
	return (0);
}