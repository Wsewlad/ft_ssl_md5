/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:46:30 by vfil              #+#    #+#             */
/*   Updated: 2017/11/04 19:04:33 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*c1;
	const unsigned char	*c2;

	c1 = (const unsigned char*)s1;
	c2 = (const unsigned char*)s2;
	while (n--)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		else
		{
			c1++;
			c2++;
		}
	}
	return (0);
}
