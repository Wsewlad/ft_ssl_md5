/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:16:09 by vfil              #+#    #+#             */
/*   Updated: 2017/11/07 17:03:33 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	y;

	i = 0;
	while (haystack[i] && i < len)
	{
		y = i;
		j = 0;
		while (haystack[y] == needle[j] && needle[j] && i < len && y < len)
		{
			y++;
			j++;
		}
		if (!needle[j])
			return ((char*)&haystack[y - j]);
		i++;
	}
	return (NULL);
}
