/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:47:29 by vfil              #+#    #+#             */
/*   Updated: 2018/01/23 14:47:35 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_len(long long ln, int *b_c, int is_neg)
{
	int	len;

	len = (is_neg == 1) ? 1 : 0;
	if (ln == 0)
		len++;
	while (ln > 0)
	{
		ln /= (long int)b_c[0];
		len++;
	}
	return (len);
}

static char		ft_base_val(int num, int caps)
{
	if (num >= 0 && num <= 9)
		return ((char)(num + '0'));
	else if (caps)
		return ((char)(num - 10 + 'A'));
	else
		return ((char)(num - 10 + 'a'));
}

static char		*ft_make_res(int len, long long ln, int *b_c, int is_neg)
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
		*res = ft_base_val(ln % b_c[0], b_c[1]);
		ln /= b_c[0];
		res++;
	}
	if (is_neg == 1)
		*res++ = '-';
	*res = '\0';
	return (res - len);
}

char			*ft_llitoa_base(long long ln, int base, int caps)
{
	int		b_c[2];
	int		len;
	int		is_neg;
	char	*res;

	b_c[0] = base;
	b_c[1] = caps;
	len = 0;
	is_neg = 0;
	res = NULL;
	if (b_c[0] >= 2 && b_c[0] <= 16)
	{
		if (ln < 0)
		{
			ln = -ln;
			if (b_c[0] == 10)
				is_neg = 1;
		}
		len = ft_find_len(ln, b_c, is_neg);
		if (!(res = ft_make_res(len, ln, b_c, is_neg)))
			return (NULL);
	}
	return (ft_strrev(res));
}
