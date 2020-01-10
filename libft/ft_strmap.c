/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:26:42 by vfil              #+#    #+#             */
/*   Updated: 2017/11/08 15:30:24 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	i = 0;
	new = NULL;
	if (s && f)
	{
		new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (new == NULL)
			return (NULL);
		while (s[i])
		{
			new[i] = (*f)(s[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
