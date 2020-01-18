

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft/libft.h"
# include <fcntl.h>
# include "ft_sha256.h"
# include "ft_md5.h"

# define NBR_OF_FUNC 2

typedef struct 		s_flag
{
	int				p;
	int				q;
	int				r;
	int				s;
	int 			f;
}					t_flag;

typedef void	(*t_hash_func)(char *, size_t);

typedef struct		s_algorithm
{
	char			*name;
	t_hash_func		func;
}					t_algorithm;

typedef struct 		s_ssl
{
	char			*input;
	size_t			input_len;
	char			*file_name;
	t_flag			flags;
	t_algorithm		algorithms[NBR_OF_FUNC];
	int				algo_idx;
}					t_ssl;

#endif
