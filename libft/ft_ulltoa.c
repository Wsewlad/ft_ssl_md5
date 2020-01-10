/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:55:13 by vfil              #+#    #+#             */
/*   Updated: 2018/01/23 14:55:17 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ulltoa(unsigned long long n)
{
	unsigned long long	i;
	int					len;
	char				*str;

	i = 1;
	len = 0;
	while (n / i > 9)
	{
		i *= 10;
		len++;
	}
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (str);
	len = 0;
	while (i > 0)
	{
		str[len] = n / i + '0';
		n %= i;
		i /= 10;
		len++;
	}
	str[len] = '\0';
	return (str);
}
