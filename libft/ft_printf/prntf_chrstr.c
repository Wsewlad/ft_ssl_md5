/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prntf_chrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:20:08 by vfil              #+#    #+#             */
/*   Updated: 2018/01/17 15:20:10 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		convert_chr(t_list **res, t_spec_elem spec, va_list ap)
{
	char c;

	if (!ft_strcmp(spec.smod, "l") && spec.cletter == 'c')
		convert_unichr(res, spec, ap);
	else
	{
		c = (spec.cletter == 'c') ? va_arg(ap, int) : spec.cletter;
		if (!spec.flags.minus)
		{
			push_padding(res, spec.fwidth ? spec.fwidth - 1 : spec.fwidth, \
			spec, spec.precision != -1 ? 1 : 0);
			fill_buf_chr(res, c);
		}
		else
		{
			fill_buf_chr(res, c);
			push_padding(res, spec.fwidth ? spec.fwidth - 1 : spec.fwidth, \
			spec, spec.precision != -1 ? 1 : 0);
		}
	}
}

void		convert_str(t_list **res, t_spec_elem spec, va_list ap)
{
	char	*str;

	if (!ft_strcmp(spec.smod, "l"))
		convert_unistr(res, spec, ap);
	else
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
		fill_buf_str(res, str, spec);
	}
}

static void	push_flags(t_list **res, t_spec_elem spec, \
						unsigned long long un, int *base_caps)
{
	if (spec.precision == -1)
		spec.flags.hash = 2;
	fill_buf_chr(res, '0');
	fill_buf_chr(res, 'x');
	push_unumb(res, base_caps, un, spec);
}

void		convert_ptr(t_list **res, t_spec_elem spec, va_list ap)
{
	int				base_caps[2];
	int				len;
	int				width;
	unsigned long	un;

	base_caps[0] = 16;
	base_caps[1] = 0;
	un = va_arg(ap, unsigned long);
	len = find_ulen(un, 16) + 2;
	len = (spec.precision > len) ? spec.precision : len;
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
