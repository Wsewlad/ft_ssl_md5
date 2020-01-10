/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:46:52 by vfil              #+#    #+#             */
/*   Updated: 2018/01/24 14:46:54 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		fill_buf_str(t_list **res, char *str, t_spec_elem spec)
{
	int len;
	int padd;

	len = ft_strlen(str);
	if (spec.precision != -1)
		len = (spec.precision < len) ? spec.precision : len;
	padd = (spec.fwidth > len) ? spec.fwidth - len : 0;
	if (!spec.flags.minus)
	{
		if (spec.flags.zero && spec.precision == 0 && !len)
			push_padding(res, padd, spec, 1);
		else
			push_padding(res, padd, spec, 0);
		push_str(res, len, str);
	}
	else
	{
		push_str(res, len, str);
		push_padding(res, padd, spec, 0);
	}
}

void		fill_buf_chr(t_list **str, char chr)
{
	char	*buf;
	t_list	*new;

	if (str)
	{
		if ((*str)->content_size == BUF_SIZE_PF)
		{
			new = ft_lstnew("", BUF_SIZE_PF);
			new->content_size = 0;
			(*str)->next = new;
			*str = (*str)->next;
			(*str)->content_size = 0;
		}
		buf = (char*)(*str)->content;
		buf[(*str)->content_size] = chr;
		(*str)->content_size++;
	}
}

int			print_buf(t_list **res, int fd)
{
	int		len;
	t_list	*crawler;

	len = 0;
	crawler = *res;
	while (crawler)
	{
		len += write(fd, crawler->content, crawler->content_size);
		crawler = crawler->next;
	}
	while (*res)
	{
		ft_memdel(&((*res)->content));
		crawler = (*res)->next;
		free(*res);
		*res = crawler;
	}
	*res = NULL;
	return (len);
}
