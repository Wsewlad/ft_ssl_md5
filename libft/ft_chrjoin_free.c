/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 19:55:08 by vfil              #+#    #+#             */
/*   Updated: 2018/01/16 19:55:12 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_chrjoin_free(char **s1, char s2)
{
	char	*new;
	char	*s01;
	int		i;

	new = NULL;
	i = 0;
	if (*s1 && s2)
	{
		s01 = *s1;
		if ((new = ft_strnew(ft_strlen(*s1) + 1)))
		{
			while (*s01)
			{
				new[i++] = *s01;
				s01++;
			}
			new[i++] = s2;
			new[i] = '\0';
			ft_strdel(s1);
			*s1 = ft_strdup(new);
			ft_strdel(&new);
		}
	}
}
