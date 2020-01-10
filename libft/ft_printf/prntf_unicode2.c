/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prntf_unicode2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:55:28 by vfil              #+#    #+#             */
/*   Updated: 2018/01/26 16:55:30 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	get_two_bytes(t_list **res, unsigned int u)
{
	unsigned int	mask02;
	unsigned char	p1;
	unsigned char	p2;

	mask02 = 49280;
	p2 = (u << 26) >> 26;
	p1 = ((u >> 6) << 27) >> 27;
	fill_buf_chr(res, (char)((mask02 >> 8) | p1));
	fill_buf_chr(res, (char)(((mask02 << 24) >> 24) | p2));
}

static void	get_three_bytes(t_list **res, unsigned int u)
{
	unsigned int	mask03;
	unsigned char	p1;
	unsigned char	p2;
	unsigned char	p3;

	mask03 = 14712960;
	p3 = (u << 26) >> 26;
	p2 = ((u >> 6) << 26) >> 26;
	p1 = ((u >> 12) << 28) >> 28;
	fill_buf_chr(res, (char)((mask03 >> 16) | p1));
	fill_buf_chr(res, (char)(((mask03 << 16) >> 24) | p2));
	fill_buf_chr(res, (char)(((mask03 << 24) >> 24) | p3));
}

static void	get_four_bytes(t_list **res, unsigned int u)
{
	unsigned int	mask04;
	unsigned char	p1;
	unsigned char	p2;
	unsigned char	p3;
	unsigned char	p4;

	mask04 = 4034953344;
	p4 = (u << 26) >> 26;
	p3 = ((u >> 6) << 26) >> 26;
	p2 = ((u >> 12) << 26) >> 26;
	p1 = ((u >> 18) << 28) >> 28;
	fill_buf_chr(res, (char)((mask04 >> 24) | p1));
	fill_buf_chr(res, (char)(((mask04 << 8) >> 24) | p2));
	fill_buf_chr(res, (char)(((mask04 << 16) >> 24) | p3));
	fill_buf_chr(res, (char)(((mask04 << 24) >> 24) | p4));
}

void		get_symbol(t_list **res, unsigned int numb)
{
	int				bytes;

	bytes = count_bytes(numb);
	if (bytes == 1 || MB_CUR_MAX == 1)
		fill_buf_chr(res, (char)numb);
	else if (bytes == 2)
		get_two_bytes(res, numb);
	else if (bytes == 3)
		get_three_bytes(res, numb);
	else if (bytes == 4)
		get_four_bytes(res, numb);
}
