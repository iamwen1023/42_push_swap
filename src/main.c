/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:51:20 by wlo               #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/09/10 23:15:10 by wlo              ###   ########.fr       */
=======
/*   Updated: 2021/09/10 18:13:24 by wlo              ###   ########.fr       */
>>>>>>> a410c19ccb002b009b186f14be22533c8d094ce6
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
<<<<<<< HEAD

=======
#include <stdio.h>
>>>>>>> a410c19ccb002b009b186f14be22533c8d094ce6
int	main(int argc, char **argv)
{
	t_listd	*arr;

	if (check_error(argc, argv) == 1)
		error_exit();
	arr = parse_lst(argc, argv);
<<<<<<< HEAD
=======
	print_out(arr);
>>>>>>> a410c19ccb002b009b186f14be22533c8d094ce6
	if (confrim_sort(arr) == 1)
		return (0);
	if (argc <= 4)
		small_sort_3(&arr, arr);
	else if (argc <= 6)
		small_sort_5(&arr);
	else
		radix_sort(&arr, argc - 1);
	return (0);
<<<<<<< HEAD
}
=======
}
>>>>>>> a410c19ccb002b009b186f14be22533c8d094ce6
