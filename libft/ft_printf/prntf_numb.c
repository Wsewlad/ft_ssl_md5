/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prntf_numb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:40:38 by vfil              #+#    #+#             */
/*   Updated: 2018/01/12 17:40:43 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	convert_dibd(t_list **res, t_spec_elem spec, va_list ap)
{
	if (spec.cletter == 'D')
		lltoa_buf(res, va_arg(ap, long long), spec);
	else if (!ft_strcmp(spec.smod, ""))
		lltoa_buf(res, va_arg(ap, int), spec);
	else if (!ft_strcmp(spec.smod, "l"))
		lltoa_buf(res, va_arg(ap, long), spec);
	else if (!ft_strcmp(spec.smod, "ll"))
		lltoa_buf(res, va_arg(ap, long long), spec);
	else if (!ft_strcmp(spec.smod, "h"))
		lltoa_buf(res, (short)va_arg(ap, int), spec);
	else if (!ft_strcmp(spec.smod, "hh"))
		lltoa_buf(res, (signed char)va_arg(ap, int), spec);
	else if (!ft_strcmp(spec.smod, "j"))
		lltoa_buf(res, va_arg(ap, intmax_t), spec);
	else if (!ft_strcmp(spec.smod, "z"))
		lltoa_buf(res, va_arg(ap, size_t), spec);
}

void	convert_unsigned(t_list **res, t_spec_elem spec, va_list ap)
{
	int	base_caps[2];

	base_caps[0] = (spec.cletter == 'o' || spec.cletter == 'O') ? 8 : 10;
	if (spec.cletter == 'x' || spec.cletter == 'X')
		base_caps[0] = 16;
	base_caps[1] = (spec.cletter == 'X') ? 1 : 0;
	if (!ft_strcmp(spec.smod, ""))
		ulltoa_base_buf(res, va_arg(ap, unsigned int), base_caps, spec);
	else if (!ft_strcmp(spec.smod, "l"))
		ulltoa_base_buf(res, va_arg(ap, unsigned long), base_caps, spec);
	else if (!ft_strcmp(spec.smod, "ll"))
		ulltoa_base_buf(res, va_arg(ap, unsigned long long), base_caps, spec);
	else if (!ft_strcmp(spec.smod, "h"))
		ulltoa_base_buf(res, (unsigned short)va_arg(ap, unsigned int),
						base_caps, spec);
	else if (!ft_strcmp(spec.smod, "hh"))
		ulltoa_base_buf(res, (unsigned char)va_arg(ap, unsigned int),
						base_caps, spec);
	else if (!ft_strcmp(spec.smod, "j"))
		ulltoa_base_buf(res, va_arg(ap, uintmax_t), base_caps, spec);
	else if (!ft_strcmp(spec.smod, "z"))
		ulltoa_base_buf(res, va_arg(ap, size_t), base_caps, spec);
}

void	convert_bou(t_list **res, t_spec_elem spec, va_list ap)
{
	int	base_caps[2];

	base_caps[0] = (spec.cletter == 'o' || spec.cletter == 'O') ? 8 : 10;
	if (spec.cletter == 'x' || spec.cletter == 'X')
		base_caps[0] = 16;
	base_caps[1] = (spec.cletter == 'X') ? 1 : 0;
	if (spec.cletter == 'O' || spec.cletter == 'U')
		ulltoa_base_buf(res, va_arg(ap, unsigned long), base_caps, spec);
}
