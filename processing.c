/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:06:56 by vfil              #+#    #+#             */
/*   Updated: 2020/01/18 16:06:57 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	process_file(t_ssl *ssl, char *file_name)
{
	if (read_file(ssl, file_name))
	{
		if (!ssl->flags.r && !ssl->flags.q)
			ft_printf("%s (%s) = ",
				ft_str2upper(ssl->algorithms[ssl->algo_idx].name), file_name);
		ssl->algorithms[ssl->algo_idx].func(ssl->input, ssl->input_len);
		if (ssl->flags.r && !ssl->flags.q)
			ft_printf(" %s", file_name);
		ft_printf("\n");
		free(ssl->input);
	}
	ssl->flags.f = 1;
}

void	process_stdin(t_ssl *ssl, int print_input)
{
	if (read_stdin(ssl))
	{
		if (print_input)
		{
			ft_printf("%s", ssl->input);
			ssl->flags.p = 1;
		}
		ssl->algorithms[ssl->algo_idx].func(ssl->input, ssl->input_len);
		ft_printf("\n");
		free(ssl->input);
	}
}

void	process_string(t_ssl *ssl, char *str, int *i)
{
	if (!ssl->flags.r && !ssl->flags.q)
		ft_printf("%s (\"%s\") = ",
			ft_str2upper(ssl->algorithms[ssl->algo_idx].name), str);
	ssl->algorithms[ssl->algo_idx].func(str, ft_strlen(str));
	if (ssl->flags.r && !ssl->flags.q)
		ft_printf(" \"%s\"", str);
	ft_printf("\n");
	ssl->flags.s = 1;
	(*i)++;
}
