/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 20:41:39 by vfil              #+#    #+#             */
/*   Updated: 2018/02/19 20:45:03 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int nb, int pow)
{
	int	sum;

	sum = nb;
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	while (pow > 1)
	{
		sum *= nb;
		pow--;
	}
	return (sum);
}
