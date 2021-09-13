/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:14:44 by wlo               #+#    #+#             */
/*   Updated: 2021/09/10 16:14:49 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*origin;
	size_t			i;

	origin = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*origin = c;
		origin++;
		i++;
	}
	return (s);
}
