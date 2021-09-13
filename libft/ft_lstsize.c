/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:13:17 by wlo               #+#    #+#             */
/*   Updated: 2021/09/10 16:13:21 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		i;

	if (lst == 0)
		return (0);
	current = lst->next;
	i = 1;
	while (current != 0)
	{
		i++;
		current = current->next;
	}
	return (i);
}
