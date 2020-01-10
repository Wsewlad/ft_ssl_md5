/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:13:01 by vfil              #+#    #+#             */
/*   Updated: 2017/11/04 16:57:12 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst2;
	unsigned char	*src2;

	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	while (n--)
	{
		*dst2 = *src2;
		if (*src2 == (unsigned char)c)
			return (++dst2);
		dst2++;
		src2++;
	}
	return (NULL);
}
