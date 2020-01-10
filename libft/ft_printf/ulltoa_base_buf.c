/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltoa_base_buf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:03:44 by vfil              #+#    #+#             */
/*   Updated: 2018/02/02 13:03:45 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			find_ulen(unsigned long long un, int base)
{
	int	len;

	len = 0;
	if (un == 0)
		len++;
	while (un > 0)
	{
		un /= (unsigned long long)base;
		len++;
	}
	return (len);
}

void		push_unumb(t_list **res, int *base_caps, unsigned long long un, \
t_spec_elem spec)
{
	unsigned long long	pow;
	const char			ltr[24] = "0123456789abcdefABCDEF";
	int					len;
	int					prec;

	len = find_ulen(un, base_caps[0]);
	pow = 1;
	while ((len--) - 1)
		pow *= base_caps[0];
	len = find_ulen(un, base_caps[0]);
	prec = 0;
	if (spec.precision != -1)
		prec = spec.precision > len ? spec.precision - len : 0;
	else if (spec.flags.zero && !spec.flags.minus)
		prec = spec.fwidth > len ? spec.fwidth - len : 0;
	prec = prec - spec.flags.hash;
	push_padding(res, prec > 0 ? prec : 0, spec, 1);
	pow = (!un && spec.precision == 0) ? 0 : pow;
	while (pow)
	{
		fill_buf_chr(res, (base_caps[1] && (un / pow) > 9) ? \
		ltr[(un / pow) + 6] : ltr[un / pow]);
		un %= pow;
		pow /= base_caps[0];
	}
}

static void	push_flags(t_list **res, t_spec_elem spec, unsigned long long un, \
int *base_caps)
{
	if (spec.flags.hash && un && (base_caps[0] == 8 || base_caps[0] == 16))
		fill_buf_chr(res, '0');
	if (spec.flags.hash && !un && spec.precision == 0 && base_caps[0] == 8)
		fill_buf_chr(res, '0');
	if (un && spec.flags.hash && base_caps[0] == 16)
		fill_buf_chr(res, spec.cletter == 'x' ? 'x' : 'X');
	if (!(!un && spec.precision != -1 && base_caps[0] == 8 && spec.flags.hash))
	{
		spec.flags.hash = (spec.flags.hash == 2 && spec.precision != -1) ? 0 : \
							spec.flags.hash;
		push_unumb(res, base_caps, un, spec);
	}
}

void		ulltoa_base_buf(t_list **res, unsigned long long un,
							int *base_caps, t_spec_elem spec)
{
	int	len;
	int width;

	len = (!un && spec.precision == 0) ? 0 : find_ulen(un, base_caps[0]);
	len = (spec.precision > len) ? spec.precision : len;
	if (spec.flags.hash && spec.cletter != 'u')
		spec.flags.hash = (spec.cletter == 'x' || spec.cletter == 'X') ? 2 : 1;
	else
		spec.flags.hash = 0;
	len = len + spec.flags.hash;
	width = (spec.fwidth > len && (!spec.flags.zero || spec.flags.minus \
			|| spec.precision != -1)) ? spec.fwidth : len;
	if (spec.flags.minus)
		push_flags(res, spec, un, base_caps);
	while (width > len)
	{
		fill_buf_chr(res, ' ');
		width--;
	}
	if (!spec.flags.minus)
		push_flags(res, spec, un, base_caps);
}
