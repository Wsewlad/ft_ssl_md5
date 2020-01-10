/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init_specification.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:45:32 by vfil              #+#    #+#             */
/*   Updated: 2018/02/11 18:53:40 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_init_specification(char *format, t_spec_elem *spec, va_list ap)
{
	int	step;
	int len;

	len = ft_strlen(format);
	step = 0;
	init_spec2zero(spec);
	while (*format && (!(spec->cletter) || !step))
	{
		if (!len && !(spec->cletter))
			return (0);
		check_init_flags(format, &step, spec);
		check_init_fwidth(format, &step, spec, ap);
		check_init_precision(format, &step, spec, ap);
		check_init_modifiers(format, &step, spec);
		check_init_specifier(format, &step, spec);
		len--;
	}
	return (step);
}

void	init_spec2zero(t_spec_elem *spec)
{
	spec->flags.minus = 0;
	spec->flags.plus = 0;
	spec->flags.zero = 0;
	spec->flags.hash = 0;
	spec->flags.space = 0;
	spec->fwidth = 0;
	spec->precision = -1;
	ft_bzero(spec->smod, 3);
	spec->cletter = '\0';
}

void	check_init_flags(char *format, int *step, t_spec_elem *spec)
{
	format += *step;
	while (*format && is_flag(*format))
	{
		if (*format == '-')
			spec->flags.minus = 1;
		else if (*format == '+')
			spec->flags.plus = 1;
		else if (*format == '0')
			spec->flags.zero = 1;
		else if (*format == '#')
			spec->flags.hash = 1;
		else if (*format == ' ')
			spec->flags.space = 1;
		format++;
		(*step)++;
	}
}

void	check_init_fwidth(char *format, int *step, t_spec_elem *spec, \
						va_list ap)
{
	int w;

	format += *step;
	if (*format && *format == '*')
	{
		w = va_arg(ap, int);
		if (w < 0)
		{
			w = -w;
			spec->flags.minus = 1;
		}
		spec->fwidth = w;
		format++;
		(*step)++;
	}
	if (*format && *format != '0' && *format != '-' && ft_atoi(format) != 0)
	{
		spec->fwidth = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
		{
			format++;
			(*step)++;
		}
	}
}

void	check_init_precision(char *format, int *step, t_spec_elem *spec, \
							va_list ap)
{
	int prec;

	format += *step;
	if (*format && *format == '.')
	{
		format++;
		(*step)++;
		if (*format == '*')
		{
			prec = va_arg(ap, int);
			spec->precision = prec < 0 ? -1 : prec;
			format++;
			(*step)++;
		}
		else
		{
			spec->precision = (*format == '-') ? 0 : ft_atoi(format);
			while (*format >= '0' && *format <= '9')
			{
				format++;
				(*step)++;
			}
		}
	}
}
