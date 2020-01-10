/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:58:40 by vfil              #+#    #+#             */
/*   Updated: 2017/12/19 14:43:28 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_file(const int fd, t_list *lst)
{
	char	*buf;
	char	*buf2;
	int		ret;

	buf = ft_strnew(BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) && ret != -1)
	{
		buf[ret] = '\0';
		buf2 = lst->content;
		lst->content = ft_strjoin(buf2, buf);
		ft_strdel(&buf2);
		ft_strdel(&buf);
		if (ft_strchr(lst->content, '\n') || ret != BUFF_SIZE)
			return (ret);
		buf = ft_strnew(BUFF_SIZE + 1);
	}
	ft_strdel(&buf);
	return (ret);
}

static int	divide(char **line, t_list *lst)
{
	char	*ln;
	char	*buf;

	ln = ft_strchr((char*)lst->content, '\n');
	if (ln)
	{
		*line = ft_strsub(lst->content, 0, ln - (char*)lst->content);
		buf = ft_strdup(ln + 1);
		ft_memdel(&lst->content);
		lst->content = ft_strdup(buf);
		ft_strdel(&buf);
		return (0);
	}
	*line = ft_strdup(lst->content);
	ft_memdel(&lst->content);
	lst->content = ft_strnew(0);
	return (**line ? 0 : 1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*lst;
	int				ret;

	ret = 1;
	if (fd < 0 || !line)
		return (-1);
	lst = head;
	while (lst && lst->content_size != (size_t)fd)
		lst = lst->next;
	if (!lst && (lst = ft_lstnew("", 1)))
	{
		lst->content_size = fd;
		ft_lstadd(&head, lst);
	}
	if (lst->content && !ft_strchr(lst->content, '\n'))
		ret = read_file(fd, lst);
	if (ret < 0)
		return (-1);
	if (lst->content && !(divide(line, lst)))
		return (1);
	return (0);
}
