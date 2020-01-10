/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:29:17 by vfil              #+#    #+#             */
/*   Updated: 2017/11/08 15:03:16 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_arr(long int ln, long int i, int len, int min)
{
	long int	j;
	char		*str;

	j = 0;
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (str);
	if (min)
		str[j++] = '-';
	while (i > 0)
	{
		str[j] = ln / i + '0';
		ln %= i;
		i /= 10;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	long int	ln;
	long int	i;
	int			len;
	int			min;

	ln = n;
	i = 1;
	len = 0;
	min = 0;
	if (ln < 0)
	{
		min = 1;
		ln *= -1;
		len++;
	}
	while (ln / i > 9)
	{
		i *= 10;
		len++;
	}
	return (ft_fill_arr(ln, i, len, min));
}
