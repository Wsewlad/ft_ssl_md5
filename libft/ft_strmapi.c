/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:55:42 by vfil              #+#    #+#             */
/*   Updated: 2017/11/08 15:31:44 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	new = NULL;
	i = 0;
	if (s && f)
	{
		new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (new == NULL)
			return (new);
		while (s[i])
		{
			new[i] = (*f)(i, s[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
