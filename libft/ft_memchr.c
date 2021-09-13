/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:13:50 by wlo               #+#    #+#             */
/*   Updated: 2021/09/10 16:13:53 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ch_str;
	size_t			i;

	ch_str = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (ch_str[i] == (unsigned char)c)
			return ((void *)str + i);
		i++;
	}
	return (0);
}
