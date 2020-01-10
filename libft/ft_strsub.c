/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:46:29 by vfil              #+#    #+#             */
/*   Updated: 2017/11/04 14:07:14 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	new = NULL;
	i = 0;
	if (s && s[start] && (new = (char*)malloc(sizeof(char) * (len + 1))))
	{
		while (i < len && s[start])
		{
			new[i] = s[start];
			i++;
			start++;
		}
		new[i] = '\0';
	}
	return (new);
}
