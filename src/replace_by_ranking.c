/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_by_ranking.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:23:59 by wlo               #+#    #+#             */
/*   Updated: 2021/09/08 17:47:45 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void print_out_2(int *arr, int argc)
{
	int i = 0;
	ft_putstr_fd("arr: ", 1);
	while(i < argc -1)
	{
		ft_putnbr_fd(arr[i], 1);
		i++;
	}
	ft_putstr_fd("\n" , 1);
}

int *sort_arry(int argc, char**argv)
{
	int *arr;
	int i;
	int y;

	arr = (int*)malloc((argc-1) * sizeof(int));
	if (!arr)
		return (0);
	i = -1;
	while(++i < argc - 1)
		arr[i] = ft_atoi(argv[i+1]);
	i = -1;
	while(++i < argc-2)
	{
		y = -1;
		while(++y < argc-2-i)
		{
			if (arr[y] > arr[y+1])
				swap(&arr[y], &arr[y+1]);
		}
	}
	return arr;
}

void replace_by_ranking(t_listd **arr, int argc, char**argv)
{
	int i;
	int *arr_int;
	t_listd *current;

	arr_int = sort_arry(argc, argv);
	current = (*arr);
	while(current)
	{
		i = -1;
		while(++i < argc - 1)
		{
			if(current->content == arr_int[i])
			{
				current->content = i;
				break;
			}
		}
		current = current->next;
	}
}
