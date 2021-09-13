/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:52:18 by wlo               #+#    #+#             */
/*   Updated: 2021/09/13 18:12:49 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort_3_2(t_listd **arr, t_listd *current)
{
	if (current->content == the_max(*arr))
	{
		current = current->next;
		if (current->content == the_min(*arr))
			rotate_a(arr);
		else
		{
			swap_a(arr);
			r_rotate_a(arr);
		}
	}
	else if (current->content == the_min(*arr))
	{
		swap_a(arr);
		rotate_a(arr);
	}
	else
	{
		current = current->next;
		if (current->content == the_min(*arr))
			swap_a(arr);
		else
			r_rotate_a(arr);
	}
}

void	small_sort_3(t_listd **arr, t_listd *current)
{
	if (!(*arr)->content || !current)
		return ;
	small_sort_3_2(arr, current);
}

void	small_sort_5_2(t_listd	**arr, t_listd **arr_b)
{
	if (confrim_sort(*arr) == 1 && (*arr_b)->content == the_max(*arr) - 1)
	{
		r_rotate_a(arr);
		push_a(arr, arr_b);
	}
	else if (!(*arr_b) && ((*arr)->content < 3))
		r_rotate_a(arr);
	else
		rotate_a(arr);
}

void	small_sort_5(t_listd **arr)
{
	t_listd	*arr_b;

	arr_b = 0;
	push_b(arr, &arr_b);
	push_b(arr, &arr_b);
	if (confrim_sort(*arr) == 0)
		small_sort_3(arr, *arr);
	while (confrim_sort(*arr) == 0 || arr_b)
	{
		if ((arr_b) && arr_b->content == (*arr)->content - 1)
			push_a(arr, &arr_b);
		else if ((arr_b) && arr_b->content == (*arr)->content + 1)
		{
			rotate_a(arr);
			push_a(arr, &arr_b);
		}	
		else if (confrim_sort(*arr) == 1 && arr_b->content > the_max(*arr))
			push_a(arr, &arr_b);
		else if (confrim_sort(*arr) == 1 && arr_b->content < the_min(*arr))
			push_a(arr, &arr_b);
		else
			small_sort_5_2(arr, &arr_b);
	}
}
