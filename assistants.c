/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:26:50 by vfil              #+#    #+#             */
/*   Updated: 2020/01/18 15:26:55 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		is_command_valid(t_ssl *ssl, char *command_name)
{
	int i;

	i = -1;
	while (++i < NBR_OF_FUNC)
		if (ft_strcmp(command_name, ssl->algorithms[i].name) == 0)
			ssl->algo_idx = i;
	if (ssl->algo_idx == -1)
		return (print_error(command_name, ssl));
	return (1);
}

int		print_error(char *str, t_ssl *ssl)
{
	int i;

	if (str == NULL)
		ft_putstr("usage: ft_ssl command [command opts] [command args]\n");
	else
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", str);
		ft_putstr("\nStandard commands:\n");
		ft_putstr("\nMessage Digest commands:\n");
		i = -1;
		while (++i < NBR_OF_FUNC)
			ft_printf("%s\n", ssl->algorithms[i].name);
		ft_putstr("\nCipher commands:\n");
	}
	return (0);
}

int		read_stdin(t_ssl *ssl)
{
	int		fd;
	char	buff[2];
	char	*tmp;

	fd = 0;
	ssl->input_len = 0;
	ft_memset(buff, 0, 2);
	ssl->input = ft_strdup("");
	while (read(fd, buff, 1) > 0)
	{
		tmp = ssl->input;
		ssl->input = ft_strjoin(ssl->input, buff);
		free(tmp);
	}
	ssl->input_len = ft_strlen(ssl->input);
	return (1);
}

int		read_file(t_ssl *ssl, char *file_name)
{
	int		ret;
	int		fd;
	char	c;

	ssl->input_len = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_printf("ft_ssl: %s: %s: No such file or directory\n",
			ssl->algorithms[ssl->algo_idx].name, file_name);
		return (0);
	}
	while ((ret = read(fd, &c, 1)) > 0)
		ssl->input_len++;
	if (ret < 0)
	{
		ft_printf("%s: %s: Is a directory\n",
			ssl->algorithms[ssl->algo_idx].name, file_name);
		return (0);
	}
	ssl->input = (char*)malloc(sizeof(char) * (ssl->input_len));
	close(fd);
	fd = open(file_name, O_RDONLY);
	read(fd, ssl->input, ssl->input_len);
	close(fd);
	return (1);
}

char	*ft_str2upper(char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = ft_strnew(ft_strlen(str));
	while (str[i])
	{
		res[i] = ft_toupper(str[i]);
		i++;
	}
	return (res);
}
