/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:19:20 by vfil              #+#    #+#             */
/*   Updated: 2017/11/08 18:20:56 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	res;
	int		n;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	if (dst[i] == '\0')
		res = i + ft_strlen(src);
	else
		res = dstsize + ft_strlen(src);
	if ((n = dstsize - ft_strlen(dst) - 1) > 0)
		dst = ft_strncat(dst, src, n);
	return (res);
}
