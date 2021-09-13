/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:14:30 by wlo               #+#    #+#             */
/*   Updated: 2021/09/10 16:14:35 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*ch_str1;
	unsigned char	*ch_str2;
	size_t			i;

	if (str1 == 0 && str2 == 0)
		return (0);
	if (n == 0)
		return (str1);
	if (str1 < str2)
		return (ft_memcpy(str1, str2, n));
	i = n - 1;
	ch_str1 = (unsigned char *)str1;
	ch_str2 = (unsigned char *)str2;
	while (str1 >= str2 && i > 0)
	{
		ch_str1[i] = ch_str2[i];
		i--;
	}
	ch_str1[i] = ch_str2[i];
	return (str1);
}
