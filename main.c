#include "ft_ssl.h"

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
	return 1;
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
		return 0;
	}

	while ((ret = read(fd, &c, 1)) > 0)
		ssl->input_len++;
	if (ret < 0)
	{
		ft_printf("%s: %s: Is a directory\n", 
			ssl->algorithms[ssl->algo_idx].name, file_name);
		return 0;
	}


	ssl->input = (char*)malloc(sizeof(char) * (ssl->input_len));
	close(fd);

	fd = open(file_name, O_RDONLY);
	read(fd, ssl->input, ssl->input_len);
	close(fd);
	return 1;
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
	return 0;
}


// void 	run_command(t_ssl *ssl, int ac, char **av)
// {
// 	int i;

// 	i = 2;
// 	while (i < ac)
// 	{
// 		if (!ft_strcmp(av[i], "-p"))
// 			continue;
// 		else if (!ft_strcmp(av[i], "-q"))
// 			continue;
// 		else if (!ft_strcmp(av[i], "-r"))
// 			continue;
// 		else
			
// 		i++;
// 	}
//}
char	*ft_str2upper(char *str)
{
	int 	i;
	char	*res;

	i = 0;
	res = ft_strnew(ft_strlen(str));
	while (str[i])
	{
		res[i] = ft_toupper(str[i]);
		i++;
	}
	return res;
}

void	check_command_opts(t_ssl *ssl, int ac, char **av)
{
	int i;

	i = 2;
	while (i < ac)
	{
		if (ssl->flags.f)
		{
			if (read_file(ssl, av[i]))
			{
				if (!ssl->flags.r && !ssl->flags.q)
					ft_printf("%s (%s) = ", ft_str2upper(ssl->algorithms[ssl->algo_idx].name), av[i]);
				ssl->algorithms[ssl->algo_idx].func(ssl->input, ssl->input_len);
				if (ssl->flags.r && !ssl->flags.q)
					ft_printf(" %s", av[i]);
				ft_printf("\n");
				free(ssl->input);
			}
		}
		else if (!ft_strcmp(av[i], "-p"))
		{
			if (read_stdin(ssl))
			{
				ft_printf("%s", ssl->input);
				ssl->algorithms[ssl->algo_idx].func(ssl->input, ssl->input_len);
				ft_printf("\n");
				free(ssl->input);
			}
			ssl->flags.p = 1;
		}
		else if (!ft_strcmp(av[i], "-q"))
			ssl->flags.q = 1;
		else if (!ft_strcmp(av[i], "-r"))
			ssl->flags.r = 1;
		else if (!ft_strcmp(av[i], "-s"))
		{
			if (av[i + 1])
			{
				if (!ssl->flags.r && !ssl->flags.q)
					ft_printf("%s (\"%s\") = ", ft_str2upper(ssl->algorithms[ssl->algo_idx].name), av[i + 1]);
				ssl->algorithms[ssl->algo_idx].func(av[i + 1], ft_strlen(av[i + 1]));
				if (ssl->flags.r && !ssl->flags.q)
					ft_printf(" \"%s\"", av[i + 1]);
				ft_printf("\n");
				ssl->flags.s = 1;
				i++;
			}
		}
		else
		{
			if (read_file(ssl, av[i]))
			{
				if (!ssl->flags.r && !ssl->flags.q)
					ft_printf("%s (%s) = ", ft_str2upper(ssl->algorithms[ssl->algo_idx].name), av[i]);
				ssl->algorithms[ssl->algo_idx].func(ssl->input, ssl->input_len);
				if (ssl->flags.r && !ssl->flags.q)
					ft_printf(" %s", av[i]);
				ft_printf("\n");
				free(ssl->input);
				ssl->flags.f = 1;
			}
		}
		i++;
	}
	if (!ssl->flags.f && !ssl->flags.s)
		if (read_stdin(ssl))
		{
			ssl->algorithms[ssl->algo_idx].func(ssl->input, ssl->input_len);
			ft_printf("\n");
		}
}

int		is_command_valid(t_ssl *ssl, char *commandName)
{
	int i;

	i = -1;
	while (++i < NBR_OF_FUNC)
		if (ft_strcmp(commandName, ssl->algorithms[i].name) == 0)
			ssl->algo_idx = i;

	if (ssl->algo_idx == -1)
		return print_error(commandName, ssl);

	return 1;
}


t_ssl	*ssl_init()
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
	return ssl;
}


int 	main(int argc, char **argv)
{
	t_ssl	*ssl;

	ssl = ssl_init();
	if (argc < 2)
		return (print_error(NULL, ssl));

	if (is_command_valid(ssl, argv[1]))
	{
		if (argc > 2)
		{
			check_command_opts(ssl, argc, argv);
			//run_command(ssl, argc,  argv);
		}
		else
			if (read_stdin(ssl))
			{
				ssl->algorithms[ssl->algo_idx].func(ssl->input, ssl->input_len);
				ft_printf("\n");
			}
	}
	return 0;
}