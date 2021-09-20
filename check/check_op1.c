/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:31:45 by wlo               #+#    #+#             */
/*   Updated: 2021/09/20 15:15:59 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_np(t_listd **lst)
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
}

void	swap_b_np(t_listd **lst)
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
}

void	push_a_np(t_listd **lst_a, t_listd **lst_b)
{
	t_listd	*temp;

	if (!(*lst_b))
		return ;
	temp = ft_lstnew_doubly((*lst_b)->content);
	temp->next = (*lst_b)->next;
	temp->prev = (*lst_b)->prev;
	ft_lstadd_front_doubly(lst_a, temp);
	ft_lstdel_doubly(lst_b, *lst_b);
}

void	push_b_np(t_listd **lst_a, t_listd **lst_b)
{
	t_listd	*temp;

	if (!(*lst_a))
		return ;
	temp = ft_lstnew_doubly((*lst_a)->content);
	temp->next = (*lst_a)->next;
	temp->prev = (*lst_a)->prev;
	ft_lstadd_front_doubly(lst_b, temp);
	ft_lstdel_doubly(lst_a, *lst_a);
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
