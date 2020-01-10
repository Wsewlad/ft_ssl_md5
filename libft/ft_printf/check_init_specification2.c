/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init_specification2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:54:10 by vfil              #+#    #+#             */
/*   Updated: 2018/02/11 17:48:37 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_init_modifiers(char *format, int *step, t_spec_elem *spec)
{
	format += *step;
	if (*format && is_modifier(*format))
	{
		if (spec->smod[0] == 'z' && *format == 'h')
			spec->smod[0] = 'z';
		else if (spec->smod[0] == 'j' && *format == 'h')
			spec->smod[0] = 'j';
		else
			spec->smod[0] = *format;
		spec->smod[1] = '\0';
		spec->smod[2] = '\0';
		format++;
		if (*(format - 1) == 'h' && *format == 'h')
		{
			spec->smod[1] = 'h';
			(*step)++;
		}
		else if (*(format - 1) == 'l' && *format == 'l')
		{
			spec->smod[1] = 'l';
			(*step)++;
		}
		(*step)++;
	}
}

void	check_init_specifier(char *format, int *step, t_spec_elem *spec)
{
	format += *step;
	if (*format && (is_specifier(*format) || (!is_flag(*format) && \
		!is_modifier(*format) && *format != '*' && *format != '.')))
	{
		spec->cletter = *format;
		(*step)++;
	}
}
