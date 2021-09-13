/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:18:38 by wlo               #+#    #+#             */
/*   Updated: 2021/09/10 16:18:41 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_compare(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	i;

	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *)big);
	if (len == 0)
		return (0);
	i = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			if (i + len_little > len)
				return (0);
			if (str_compare(&big[i], little) == 0)
				return ((char *)(big + i));
		}
		i++;
	}
	return (0);
}
