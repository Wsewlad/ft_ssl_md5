/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_spec_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:00:33 by vfil              #+#    #+#             */
/*   Updated: 2018/01/15 14:00:35 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_specifier(char c)
{
	char	*formats;

	formats = "sSpdDioOuUxXcC%";
	while (*formats)
	{
		if (c == *formats)
			return (1);
		formats++;
	}
	return (0);
}

int		is_flag(char c)
{
	char	*formats;

	formats = "-0+ #";
	while (*formats)
	{
		if (c == *formats)
			return (1);
		formats++;
	}
	return (0);
}

int		is_modifier(char c)
{
	char	*formats;

	formats = "hljz";
	while (*formats)
	{
		if (c == *formats)
			return (1);
		formats++;
	}
	return (0);
}
