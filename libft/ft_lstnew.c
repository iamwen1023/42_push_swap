/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:12:58 by wlo               #+#    #+#             */
/*   Updated: 2021/09/10 16:13:06 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list		*re;

	re = (t_list *)malloc(sizeof(t_list));
	if (!re)
		return (0);
	re->content = content;
	re->next = 0;
	return (re);
}
