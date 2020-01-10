#include "ft_ssl.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	char	*testStr;
	t_ssl	*ssl;

	testStr = "a";

	ssl = (t_ssl *)malloc(sizeof(t_ssl));
	ssl->hash_func = &ft_md5;

	ssl->hash_func("a");

	return 0;
}