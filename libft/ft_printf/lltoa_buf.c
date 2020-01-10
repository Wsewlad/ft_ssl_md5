/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lltoa_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:52:42 by vfil              #+#    #+#             */
/*   Updated: 2018/02/02 13:52:44 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	find_len(unsigned long long un)
{
	int	len;

	len = 0;
	if (un == 0)
		len++;
	while (un > 0)
	{
		un /= 10;
		len++;
	}
	return (len);
}

static void	push_numb(t_list **res, unsigned long long un, t_spec_elem spec, \
						int min)
{
	unsigned long long	pow;
	int					len;
	int					prec;

	len = find_len(un);
	pow = 1;
	while ((len--) - 1)
		pow *= 10;
	len = find_len(un);
	prec = 0;
	if (spec.precision != -1)
		prec = spec.precision > len ? spec.precision - len : 0;
	else if (spec.flags.zero && !spec.flags.minus)
		prec = spec.fwidth > len ? spec.fwidth - len : 0;
	prec = prec - spec.flags.space - spec.flags.plus - min;
	push_padding(res, prec > 0 ? prec : 0, spec, 1);
	pow = (!un && !spec.precision) ? 0 : pow;
	while (pow)
	{
		fill_buf_chr(res, (un / pow) + '0');
		un %= pow;
		pow /= 10;
	}
}

static void	push_flags(t_list **res, t_spec_elem spec, int min, \
						unsigned long long un)
{
	if (spec.flags.plus && !min)
		fill_buf_chr(res, '+');
	if (spec.flags.space && !spec.flags.plus && !min)
		fill_buf_chr(res, ' ');
	if (min)
		fill_buf_chr(res, '-');
	if (spec.precision != -1)
	{
		spec.flags.space = 0;
		spec.flags.plus = 0;
		min = 0;
	}
	push_numb(res, un, spec, min);
}

void		lltoa_buf(t_list **res, long long n, t_spec_elem spec)
{
	int					len;
	int					min;
	int					width;
	unsigned long long	un;

	min = n < 0 ? 1 : 0;
	un = n < 0 ? -n : n;
	len = (!un && !spec.precision) ? 0 : find_len(un);
	spec.flags.plus = min ? 0 : spec.flags.plus;
	spec.flags.space = min || spec.flags.plus ? 0 : spec.flags.space;
	len = (spec.precision > len) ? spec.precision : len;
	len = len + min + spec.flags.plus + spec.flags.space;
	width = (spec.fwidth > len && (!spec.flags.zero || spec.flags.minus \
			|| spec.precision != -1)) ? spec.fwidth : len;
	if (spec.flags.minus)
		push_flags(res, spec, min, un);
	while (width > len)
	{
		fill_buf_chr(res, ' ');
		width--;
	}
	if (!spec.flags.minus)
		push_flags(res, spec, min, un);
}
