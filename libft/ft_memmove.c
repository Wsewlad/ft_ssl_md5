/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:57:22 by vfil              #+#    #+#             */
/*   Updated: 2017/11/03 16:08:34 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	size_t			i;

	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	i = 0;
	if (dst2 > src2)
		while (len)
		{
			dst2[len - 1] = src2[len - 1];
			len--;
		}
	else
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	return (dst);
}
