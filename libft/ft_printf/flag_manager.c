/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:06:17 by vfil              #+#    #+#             */
/*   Updated: 2018/01/31 16:06:20 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	push_padding(t_list **head, int len, t_spec_elem spec, int zero)
{
	if (zero)
	{
		while (len)
		{
			fill_buf_chr(head, '0');
			len--;
		}
	}
	else
		while (len)
		{
			fill_buf_chr(head, (spec.flags.zero && !spec.flags.minus &&
					spec.precision == -1) ? '0' : ' ');
			len--;
		}
}

void	push_str(t_list **head, int len, char *str)
{
	while (*str && len)
	{
		fill_buf_chr(head, *str);
		str++;
		len--;
	}
}
