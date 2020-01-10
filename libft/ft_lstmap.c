/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:21:00 by vfil              #+#    #+#             */
/*   Updated: 2017/11/08 15:11:57 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*new_crawler;

	if (!lst || !f)
		return (NULL);
	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	tmp = (*f)(lst);
	new_crawler = ft_lstnew(tmp->content, tmp->content_size);
	new = new_crawler;
	while ((lst = lst->next))
	{
		if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		{
			ft_lstdel(&new, &ft_lstdelcont);
			return (NULL);
		}
		tmp = (*f)(lst);
		new_crawler->next = ft_lstnew(tmp->content, tmp->content_size);
		new_crawler = new_crawler->next;
	}
	new_crawler->next = NULL;
	return (new);
}
