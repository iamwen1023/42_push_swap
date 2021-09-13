/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:17:19 by wlo               #+#    #+#             */
/*   Updated: 2021/09/10 16:17:22 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length_dst;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	else if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	else
	{
		length_dst = ft_strlen(dst);
		i = 0;
		while (i + length_dst < size - 1 && src[i])
		{
			dst[length_dst + i] = src[i];
			i++;
		}
		dst[length_dst + i] = '\0';
	}
	return (length_dst + ft_strlen(src));
}
