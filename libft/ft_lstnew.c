/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:17:18 by vfil              #+#    #+#             */
/*   Updated: 2017/11/08 15:13:58 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_lst;

	new_lst = (t_list*)malloc(sizeof(t_list));
	if (new_lst)
	{
		new_lst->content = ft_memalloc(content_size);
		if (new_lst->content)
		{
			if (content)
			{
				new_lst->content = ft_memcpy(new_lst->content, content,
						content_size);
				new_lst->content_size = content_size;
			}
			else
			{
				new_lst->content = NULL;
				new_lst->content_size = 0;
			}
			new_lst->next = NULL;
		}
		else
			free(new_lst);
	}
	return (new_lst);
}
