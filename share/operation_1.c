/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:26:11 by wlo               #+#    #+#             */
/*   Updated: 2021/09/13 17:27:10 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_listd **lst)
{
	t_listd	*temp;

	if (!(*lst) || !(*lst)->next)
		return ;
	temp = ft_lstnew_doubly((*lst)->content);
	temp->next = (*lst)->next;
	temp->prev = (*lst)->prev;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next = (*lst)->next;
	(*lst)->next->content = temp->content;
	free(temp);
	write(1, "sa\n", 3);
}

void	swap_b(t_listd **lst)
{
	t_listd	*temp;

	if (!(*lst) || !(*lst)->next)
		return ;
	temp = ft_lstnew_doubly((*lst)->content);
	temp->next = (*lst)->next;
	temp->prev = (*lst)->prev;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next = (*lst)->next;
	(*lst)->next->content = temp->content;
	free(temp);
	write(1, "sb\n", 3);
}

void	push_a(t_listd **lst_a, t_listd **lst_b)
{
	t_listd	*temp;

	if (!(*lst_b))
		return ;
	temp = ft_lstnew_doubly((*lst_b)->content);
	temp->next = (*lst_b)->next;
	temp->prev = (*lst_b)->prev;
	ft_lstadd_front_doubly(lst_a, temp);
	ft_lstdel_doubly(lst_b, *lst_b);
	write(1, "pa\n", 3);
}

void	push_b(t_listd **lst_a, t_listd **lst_b)
{
	t_listd	*temp;

	if (!(*lst_a))
		return ;
	temp = ft_lstnew_doubly((*lst_a)->content);
	temp->next = (*lst_a)->next;
	temp->prev = (*lst_a)->prev;
	ft_lstadd_front_doubly(lst_b, temp);
	ft_lstdel_doubly(lst_a, *lst_a);
	write(1, "pb\n", 3);
}

int	confrim_sort(t_listd *arr)
{
	int	incre;
	int	decre;

	incre = 0;
	decre = 0;
	if (!arr || !(arr->next))
		return (1);
	while (arr->next)
	{
		if (arr->content < arr->next->content)
			incre = 1;
		if (arr->content > arr->next->content)
			decre = 1;
		arr = arr->next;
	}
	if (decre == 1)
		return (0);
	if (incre == decre)
		return (0);
	return (1);
}
