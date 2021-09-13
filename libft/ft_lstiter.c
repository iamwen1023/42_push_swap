/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:12:29 by wlo               #+#    #+#             */
/*   Updated: 2021/09/10 16:12:36 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	t_list	*current;

	if (!lst)
		return ;
	current = lst;
	while (f && current->next != 0)
	{
		(*f)(current->content);
		current = current->next;
	}
	if (f)
		f(current->content);
}
