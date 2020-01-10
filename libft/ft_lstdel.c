/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:14:13 by vfil              #+#    #+#             */
/*   Updated: 2017/11/09 18:25:49 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*crawler;
	t_list	*tmp;

	if (alst && *alst && del)
	{
		crawler = *alst;
		while (crawler)
		{
			(*del)(crawler->content, crawler->content_size);
			tmp = crawler->next;
			free(crawler);
			crawler = tmp;
		}
		*alst = NULL;
	}
}
