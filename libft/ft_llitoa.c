/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:48:43 by vfil              #+#    #+#             */
/*   Updated: 2018/01/23 14:48:46 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_arr(unsigned long long n, unsigned long long i, int len, \
int min)
{
	long long	j;
	char		*str;

	j = 0;
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (str);
	if (min)
		str[j++] = '-';
	while (i > 0)
	{
		str[j] = n / i + '0';
		n %= i;
		i /= 10;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char		*ft_llitoa(long long n)
{
	unsigned long long	i;
	unsigned long long	un;
	int					len;
	int					min;

	i = 1;
	len = 0;
	min = 0;
	if (n < 0)
	{
		min = 1;
		un = n * -1;
		len++;
	}
	else
		un = n;
	while (un / i > 9)
	{
		i *= 10;
		len++;
	}
	return (ft_fill_arr(un, i, len, min));
}
