/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:58:38 by vfil              #+#    #+#             */
/*   Updated: 2020/01/18 14:58:40 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft/libft.h"
# include <fcntl.h>
# include "ft_sha256.h"
# include "ft_md5.h"

# define NBR_OF_FUNC 2

typedef struct		s_flag
{
	int				p;
	int				q;
	int				r;
	int				s;
	int				f;
}					t_flag;

typedef void	(*t_hash_func)(char *, size_t);

typedef struct		s_algorithm
{
	char			*name;
	t_hash_func		func;
}					t_algorithm;

typedef struct		s_ssl
{
	char			*input;
	size_t			input_len;
	char			*file_name;
	t_flag			flags;
	t_algorithm		algorithms[NBR_OF_FUNC];
	int				algo_idx;
}					t_ssl;

t_ssl				*ssl_init(void);
void				check_command_opts(t_ssl *ssl, int ac, char **av);
void				process_file(t_ssl *ssl, char *file_name);
void				process_stdin(t_ssl *ssl, int print_input);
void				process_string(t_ssl *ssl, char *str, int *i);
int					is_command_valid(t_ssl *ssl, char *command_name);
int					print_error(char *str, t_ssl *ssl);
int					read_stdin(t_ssl *ssl);
int					read_file(t_ssl *ssl, char *file_name);
char				*ft_str2upper(char *str);

#endif
