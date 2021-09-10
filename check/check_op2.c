/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:34:59 by wlo               #+#    #+#             */
/*   Updated: 2021/09/10 17:51:51 by wlo              ###   ########.fr       */
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
