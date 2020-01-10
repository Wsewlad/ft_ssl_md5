/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:13:15 by vfil              #+#    #+#             */
/*   Updated: 2017/11/04 14:11:41 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	len;

	new = NULL;
	i = 0;
	j = 0;
	len = 0;
	if (s)
	{
		len = ft_strlen(s);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (i == len)
			return (ft_strnew(1));
		while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
			len--;
		if ((new = (char*)malloc(sizeof(char) * (len - i + 1))) == NULL)
			return (new);
		while (i < len)
			new[j++] = s[i++];
		new[j] = '\0';
	}
	return (new);
}
