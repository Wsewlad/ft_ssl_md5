/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:47:54 by vfil              #+#    #+#             */
/*   Updated: 2018/01/23 14:47:59 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_len(unsigned long long ln, int base)
{
	int	len;

	len = 0;
	if (ln == 0)
		len++;
	while (ln > 0)
	{
		ln /= (unsigned long long)base;
		len++;
	}
	return (len);
}

static char		ft_base_val(unsigned long long num, int caps)
{
	if (num <= 9)
		return ((char)(num + '0'));
	else if (caps)
		return ((char)(num - 10 + 'A'));
	else
		return ((char)(num - 10 + 'a'));
}

static char		*ft_make_res(int len, unsigned long long ln, int base, int caps)
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
		*res = ft_base_val(ln % (unsigned long long)base, caps);
		ln /= (unsigned long long)base;
		res++;
	}
	*res = '\0';
	return (res - len);
}

char			*ft_ulltoa_base(unsigned long long ln, int base, int caps)
{
	int		len;
	char	*res;

	len = 0;
	res = NULL;
	if (base >= 2 && base <= 16)
	{
		len = ft_find_len(ln, base);
		if (!(res = ft_make_res(len, ln, base, caps)))
			return (NULL);
	}
	return (ft_strrev(res));
}
