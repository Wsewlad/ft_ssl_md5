/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:03:46 by vfil              #+#    #+#             */
/*   Updated: 2017/11/09 16:45:24 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
			c == '\v' || c == '\f' || c == '\r');
}

int			ft_atoi(const char *str)
{
	unsigned long int	res;
	int					sign;
	int					i;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
			&& (str[i] - '0') > 7)) && sign == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
						&& (str[i] - '0') > 8)) && sign == -1)
			return (0);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(res * sign));
}
