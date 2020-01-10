/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:00:52 by vfil              #+#    #+#             */
/*   Updated: 2017/11/08 15:29:18 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;

	new = NULL;
	i = 0;
	if (s1 && s2)
	{
		if ((new = (char*)malloc(sizeof(char)
						* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		{
			while (*s1)
			{
				new[i++] = *s1;
				s1++;
			}
			while (*s2)
			{
				new[i++] = *s2;
				s2++;
			}
			new[i] = '\0';
		}
	}
	return (new);
}
