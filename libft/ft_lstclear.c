/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:11:58 by wlo               #+#    #+#             */
/*   Updated: 2021/09/10 16:12:01 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*current;
	t_list	*temps;

	if (!(*lst))
		return ;
	current = (*lst);
	while (del && current->next != 0)
	{
		(*del)(current->content);
		temps = current->next;
		free(current);
		current = temps;
	}
	if (del)
		(*del)(current->content);
	free(current);
	(*lst) = 0;
}
