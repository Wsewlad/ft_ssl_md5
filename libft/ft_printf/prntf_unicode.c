/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prntf_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:16:53 by vfil              #+#    #+#             */
/*   Updated: 2018/01/25 17:16:55 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		convert_unichr(t_list **res, t_spec_elem spec, va_list ap)
{
	if (spec.cletter)
		get_symbol(res, va_arg(ap, unsigned int));
}

int			count_bytes(unsigned int n)
{
	int bits;
	int bytes;

	bits = 0;
	bytes = 0;
	while (n)
	{
		n /= 2;
		bits++;
	}
	if (bits <= 7)
		bytes = 1;
	else if (bits <= 11)
		bytes = 2;
	else if (bits <= 16)
		bytes = 3;
	else if (bits <= 21)
		bytes = 4;
	return (bytes);
}

static void	push_flags(t_list **res, unsigned int *unistr, int prec)
{
	int	i;

	i = 0;
	while (unistr[i] && prec--)
		get_symbol(res, unistr[i++]);
}

void		find_len(unsigned int *unistr, t_spec_elem spec, \
					int *symb, int *bytes)
{
	int buf;

	*symb = 0;
	*bytes = 0;
	if (spec.precision != -1)
		while (unistr[*symb])
		{
			buf = count_bytes(unistr[*symb]);
			if ((*bytes + buf) <= spec.precision)
			{
				*bytes += buf;
				(*symb)++;
			}
			else
				break ;
		}
	else
		while (unistr[*symb])
			*bytes += count_bytes(unistr[(*symb)++]);
}

void		convert_unistr(t_list **res, t_spec_elem spec, va_list ap)
{
	unsigned int	*unistr;
	int				symb;
	int				bytes;
	int				len;

	unistr = va_arg(ap, unsigned int *);
	if (!unistr)
		fill_buf_str(res, "(null)", spec);
	else
	{
		find_len(unistr, spec, &symb, &bytes);
		len = bytes;
		if (spec.flags.minus)
			push_flags(res, unistr, symb);
		while (len < spec.fwidth)
		{
			fill_buf_chr(res, spec.flags.zero ? '0' : ' ');
			len++;
		}
		if (!spec.flags.minus)
			push_flags(res, unistr, symb);
	}
}
