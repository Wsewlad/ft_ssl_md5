/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:06:35 by vfil              #+#    #+#             */
/*   Updated: 2017/11/08 15:08:28 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*crawler;

	if (lst && f)
	{
		crawler = lst;
		while (crawler)
		{
			(*f)(crawler);
			crawler = crawler->next;
		}
	}
}
