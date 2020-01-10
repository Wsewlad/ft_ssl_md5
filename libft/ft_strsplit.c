/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 09:50:56 by vfil              #+#    #+#             */
/*   Updated: 2017/11/04 18:19:59 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_w(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i++] != c)
			counter++;
		if (s[i - 1] == c && s[i] != c && s[i] != '\0')
			counter++;
		i++;
	}
	return (counter);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		chr;
	int		w;
	int		i;

	if ((((i = 0) == 0) && (!s || !c)) ||
			!(new = (char**)malloc(sizeof(char*) * (ft_count_w(s, c) + 1))))
		return (NULL);
	w = 0;
	while (s[i] != '\0' && ((chr = 0) == 0))
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			chr++;
			i++;
		}
		if (chr && w < ft_count_w(s, c))
			if (!(new[w++] = ft_strsub(&s[i - chr], 0, chr)))
				ft_arriter(new - w, &free);
		i++;
	}
	new[w] = 0;
	return (new);
}
