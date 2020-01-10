/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 23:08:26 by vfil              #+#    #+#             */
/*   Updated: 2017/11/07 16:55:45 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int y;

	i = 0;
	while (haystack[i])
	{
		y = i;
		j = 0;
		while (haystack[y] == needle[j] && needle[j])
		{
			y++;
			j++;
		}
		if (!needle[j])
			return ((char*)&haystack[y - j]);
		i++;
	}
	if (*haystack == '\0' && *needle == '\0')
		return ((char*)haystack);
	return (NULL);
}
