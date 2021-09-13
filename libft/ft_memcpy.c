/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:14:17 by wlo               #+#    #+#             */
/*   Updated: 2021/09/10 16:14:21 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ch_dest;
	unsigned char		*ch_src;
	size_t				i;

	ch_dest = (unsigned char *)dest;
	ch_src = (unsigned char *)src;
	if (ch_dest == 0 && ch_src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		ch_dest[i] = ch_src[i];
		i++;
	}
	return (dest);
}
