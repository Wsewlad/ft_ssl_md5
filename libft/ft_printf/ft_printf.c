/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:42:46 by vfil              #+#    #+#             */
/*   Updated: 2018/02/11 22:55:47 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		prntf_parse(t_list **res, char *format, va_list ap)
{
	t_spec_elem		spec;
	int				step;
	int				i;
	const t_conv	conv[] = {{'s', &convert_str}, {'S', &convert_unistr}, \
	{'p', &convert_ptr}, {'d', &convert_dibd}, {'D', &convert_dibd}, \
	{'i', &convert_dibd}, {'o', &convert_unsigned}, {'O', &convert_bou}, \
	{'u', &convert_unsigned}, {'U', &convert_bou}, {'x', &convert_unsigned}, \
	{'X', &convert_unsigned}, {'c', &convert_chr}, {'C', &convert_unichr}, \
	{'%', &convert_chr}, {'0', NULL}};

	step = check_init_specification(format, &spec, ap);
	i = 0;
	while (conv[i].letter != spec.cletter && conv[i].letter != '0')
		i++;
	if (conv[i].letter == spec.cletter)
		conv[i].make(res, spec, ap);
	else if (spec.cletter != '\0')
		convert_chr(res, spec, ap);
	return (step);
}

void	prntf_runner(t_list **res, char *format, va_list ap, int *fd)
{
	int		step;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			step = prntf_parse(res, format, ap);
			format += step;
			if (!step)
				return ;
		}
		else if (*format)
		{
			while (*format == '{')
				format += check_color(res, format, fd, ap);
			if (*format && *format != '%')
			{
				fill_buf_chr(res, *format);
				format++;
			}
		}
	}
}

int		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	t_list	*res;
	t_list	*buf;
	int		len;
	int		fd;

	fd = 1;
	res = ft_lstnew("", BUF_SIZE_PF);
	res->content_size = 0;
	buf = res;
	va_start(ap, format);
	prntf_runner(&buf, (char*)format, ap, &fd);
	va_end(ap);
	len = print_buf(&res, fd);
	return (len);
}
