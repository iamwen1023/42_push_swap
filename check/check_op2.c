/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:34:59 by wlo               #+#    #+#             */
/*   Updated: 2021/09/20 15:07:20 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_np(t_listd **lst)
{
	t_listd	*temp;
	t_listd	*key;

	if (!(*lst) || !(*lst)->next)
		return ;
	key = (*lst);
	temp = (*lst);
	(*lst) = (*lst)->next;
	while (temp->next != 0)
		temp = temp->next;
	temp->next = key;
	key->prev = temp;
	key->next = 0;
	(*lst)->prev = 0;
}

void	rotate_b_np(t_listd **lst)
{
	t_listd	*temp;
	t_listd	*key;

	if (!(*lst) || !(*lst)->next)
		return ;
	key = (*lst);
	temp = (*lst);
	(*lst) = (*lst)->next;
	while (temp->next != 0)
		temp = temp->next;
	temp->next = key;
	key->prev = temp;
	key->next = 0;
	(*lst)->prev = 0;
}

void	r_rotate_a_np(t_listd **lst)
{
	t_listd	*temp;
	t_listd	*key;

	if (!(*lst) || !(*lst)->next)
		return ;
	temp = (*lst);
	key = temp;
	while (key->next != 0)
		key = key->next;
	key->prev->next = 0;
	temp->prev = key;
	key->next = temp;
	key->prev = 0;
	(*lst) = key;
}

void	r_rotate_b_np(t_listd **lst)
{
	t_listd	*temp;
	t_listd	*key;

	if (!(*lst) || !(*lst)->next)
		return ;
	temp = (*lst);
	key = temp;
	while (key->next != 0)
		key = key->next;
	key->prev->next = 0;
	temp->prev = key;
	key->next = temp;
	key->prev = 0;
	(*lst) = key;
}

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
	else if (!ft_strcmp(line, "ss"))
	{
		swap_a_np(arr);
		swap_b_np(arr_b);
	}
	else if (!ft_strcmp(line, ""))
		return (0);
	else
		return (1);
	return (0);
}
