/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:37:06 by vfil              #+#    #+#             */
/*   Updated: 2017/11/09 15:15:26 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_len(long int ln, int base, int is_neg)
{
	int	len;

	len = (is_neg == 1) ? 1 : 0;
	if (ln == 0)
		len++;
	while (ln > 0)
	{
		ln /= (long int)base;
		len++;
	}
	return (len);
}

static char		ft_base_val(int num)
{
	if (num >= 0 && num <= 9)
		return ((char)(num + '0'));
	return ((char)(num - 10 + 'a'));
}

static char		*ft_make_res(int len, long int ln, int base, int is_neg)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (ln == 0)
	{
		*res = '0';
		res++;
	}
	while (ln > 0)
	{
		*res = ft_base_val(ln % base);
		ln /= base;
		res++;
	}
	if (is_neg == 1)
		*res++ = '-';
	*res = '\0';
	return (res - len);
}

char			*ft_itoa_base(int n, int base)
{
	long int	ln;
	int			len;
	int			is_neg;
	char		*res;

	ln = n;
	len = 0;
	is_neg = 0;
	res = NULL;
	if (base >= 2 && base <= 16)
	{
		if (ln < 0)
		{
			ln = -ln;
			if (base == 10)
				is_neg = 1;
		}
		len = ft_find_len(ln, base, is_neg);
		if (!(res = ft_make_res(len, ln, base, is_neg)))
			return (NULL);
	}
	return (ft_strrev(res));
}
