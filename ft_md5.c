#include "ft_md5.h"

void	*md5_init(unsigned char *input_msg)
{
	t_md5			*dt;
	unsigned int 	init_len;
	unsigned int 	bits_len;

	dt = (t_md5 *)malloc(sizeof(t_md5));
	dt->h[0] = 0x67452301;
    dt->h[1] = 0xefcdab89;
    dt->h[2] = 0x98badcfe;
    dt->h[3] = 0x10325476;
    dt->offset = 0;

	init_len = ft_strlen((char *)input_msg);
	dt->new_len = ((((init_len + 8) / 64) + 1) * 64) - 8;

    dt->msg = (unsigned char *)ft_strnew(dt->new_len + 64);

    ft_memcpy(dt->msg, input_msg, init_len);
    dt->msg[init_len] = 128;

    bits_len = init_len * 8;
    ft_memcpy(dt->msg + dt->new_len, &bits_len, 4);

	return dt;
}


void	swap_and_rotate(t_md5 *dt, int i, unsigned int tmp1, unsigned int tmp2)
{
	unsigned int  z;

	z = dt->d;
	dt->d = dt->c;
	dt->c = dt->b;
	dt->b = dt->b + LEFTROTATE((dt->a + tmp1 + g_md5_k[i] + dt->tmp[tmp2]), g_md5_r[i]);
	dt->a = z;
}


void	main_algorithm_loop(t_md5 *dt, int i, unsigned int tmp1, unsigned int tmp2)
{
	while (++i < 64)
	{
		if (i < 16)
		{
			tmp1 = (dt->b & dt->c) | ((~dt->b) & dt->d);
			tmp2 = i;
		}
		else if (i < 32)
		{
			tmp1 = (dt->d & dt->b) | ((~dt->d) & dt->c);
			tmp2 = (5 * i + 1) % 16;
		}
		else if (i < 48)
		{
			tmp1 = dt->b ^ dt->c ^ dt->d;
			tmp2 = (3 * i + 5) % 16;
		}
		else
		{
			tmp1 = dt->c ^ (dt->b | (~dt->d));
			tmp2 = (7 * i) % 16;
		}
		swap_and_rotate(dt, i, tmp1, tmp2);
	}
}


void	print_md5(unsigned int h)
{
	int 			i;
	unsigned char 	*buf;

	buf = (unsigned char *)&h;
	i = -1;
	while (++i < 4)
		ft_printf("%2.2x", buf[i]);
}


void	ft_md5(void *input_msg)
{
	t_md5	*dt;
	int 	i;

	dt = md5_init((unsigned char *)input_msg);

	while (dt->offset < dt->new_len)
	{
		dt->tmp = (unsigned int *)(dt->msg + dt->offset);

		dt->a = dt->h[0];
		dt->b = dt->h[1];
		dt->c = dt->h[2];
		dt->d = dt->h[3];
		main_algorithm_loop(dt, -1, 0, 0);
		dt->h[0] += dt->a;
		dt->h[1] += dt->b;
		dt->h[2] += dt->c;
		dt->h[3] += dt->d;

		dt->offset += (512 / 8);
	}
	free(dt->msg);
	i = -1;
	while (++i < 4)
		print_md5(dt->h[i]);
}