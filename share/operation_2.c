/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:52:12 by wlo               #+#    #+#             */
/*   Updated: 2021/09/14 11:52:23 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_listd **lst)
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
	write(1, "ra\n", 3);
}

void	rotate_b(t_listd **lst)
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
	write(1, "rb\n", 3);
}

void	r_rotate_a(t_listd **lst)
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
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_listd **lst)
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
	write(1, "rrb\n", 4);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == '\0' || s2[i] == '\0')
		return (s1[i] - s2[i]);
	return (0);
}
