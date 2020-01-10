

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft/libft.h"
# include <fcntl.h>
# include "ft_sha256.h"
# include "ft_md5.h"


typedef struct 	s_ssl
{
	void	(*hash_func)(void *);
	char	*func_name;

}				t_ssl;

#endif
