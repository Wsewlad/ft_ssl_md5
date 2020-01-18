/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:58:44 by vfil              #+#    #+#             */
/*   Updated: 2020/01/18 14:58:46 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	check_command_opts(t_ssl *ssl, int ac, char **av)
{
	int i;

	i = 1;
	while (++i < ac)
	{
		if (ssl->flags.f)
			process_file(ssl, av[i]);
		else if (!ft_strcmp(av[i], "-p"))
			process_stdin(ssl, 1);
		else if (!ft_strcmp(av[i], "-q"))
			ssl->flags.q = 1;
		else if (!ft_strcmp(av[i], "-r"))
			ssl->flags.r = 1;
		else if (!ft_strcmp(av[i], "-s"))
		{
			if (av[i + 1])
				process_string(ssl, av[i + 1], &i);
			else
				print_error(NULL, ssl);
		}
		else
			process_file(ssl, av[i]);
	}
	if (!ssl->flags.f && !ssl->flags.s && !ssl->flags.p)
		process_stdin(ssl, 0);
}

t_ssl	*ssl_init(void)
{
	t_ssl	*ssl;

	ssl = (t_ssl *)malloc(sizeof(t_ssl));
	ssl->algorithms[0].name = "md5";
	ssl->algorithms[0].func = &ft_md5;
	ssl->algorithms[1].name = "sha256";
	ssl->algorithms[1].func = &ft_sha256;
	ssl->algo_idx = -1;
	ssl->flags.p = 0;
	ssl->flags.q = 0;
	ssl->flags.r = 0;
	ssl->flags.s = 0;
	ssl->flags.f = 0;
	ssl->input_len = 0;
	return (ssl);
}

int		main(int argc, char **argv)
{
	t_ssl	*ssl;

	ssl = ssl_init();
	if (argc < 2)
		return (print_error(NULL, ssl));
	if (is_command_valid(ssl, argv[1]))
	{
		if (argc > 2)
			check_command_opts(ssl, argc, argv);
		else
			process_stdin(ssl, 0);
	}
	return (0);
}
