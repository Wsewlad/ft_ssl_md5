/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:09:01 by vfil              #+#    #+#             */
/*   Updated: 2018/02/16 21:54:18 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	color_helper(t_list **res, char *format, t_spec_elem *spec,
					const t_clr col[11])
{
	int	i;

	i = 0;
	while (col[i].tmp)
	{
		if (ft_strnstr(format, col[i].tmp, 5))
		{
			fill_buf_str(res, col[i].code, *spec);
			return (5);
		}
		i++;
	}
	return (0);
}

int	check_color(t_list **res, char *format, int *fd, va_list ap)
{
	t_spec_elem	spec;
	int			ret;
	const t_clr	col[] = {{"{blk}", "\e[30m"}, {"{red}", "\e[31m"}, \
	{"{grn}", "\e[32m"}, {"{yel}", "\e[33m"}, {"{blu}", "\e[34m"}, \
	{"{mag}", "\e[35m"}, {"{cyn}", "\e[36m"}, {"{gry}", "\e[37m"}, \
	{"{bld}", "\e[1m"}, {"{eoc}", "\e[0m"}, {NULL, NULL}};

	init_spec2zero(&spec);
	if ((ret = color_helper(res, format, &spec, col)))
		return (ret);
	if (ft_strnstr(format, "{file}", 6))
	{
		*fd = va_arg(ap, int);
		return (6);
	}
	else
		fill_buf_chr(res, *format);
	return (1);
}
