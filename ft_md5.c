#include "ft_md5.h"

void	*md5_init(unsigned char *input_msg)
{
	t_md5			*data;
	unsigned int 	init_len;
	unsigned int 	bits_len;

	data = (t_md5 *)malloc(sizeof(t_md5));
	data->h[0] = 0x67452301;
    data->h[1] = 0xefcdab89;
    data->h[2] = 0x98badcfe;
    data->h[3] = 0x10325476;
    data->offset = 0;

	init_len = ft_strlen((char *)input_msg);
	data->new_len = ((((init_len + 8) / 64) + 1) * 64) - 8;

    data->msg = (unsigned char *)ft_strnew(data->new_len + 64);

    ft_memcpy(data->msg, input_msg, init_len);
    data->msg[init_len] = 128;

    bits_len = init_len * 8;
    ft_memcpy(data->msg + data->new_len, &bits_len, 4);

	return data;
}


void	swap_and_rotate(t_md5 *data, int i, unsigned int tmp1, unsigned int tmp2)
{
	unsigned int  z;

	z = data->d;
	data->d = data->c;
	data->c = data->b;
	data->b = data->b + LEFTROTATE((data->a + tmp1 + g_md5_k[i] + data->tmp[tmp2]), g_md5_r[i]);
	data->a = z;
}


void	main_algorithm_loop(t_md5 *data, int i, unsigned int tmp1, unsigned int tmp2)
{
	while (++i < 64)
	{
		if (i < 16)
		{
			tmp1 = (data->b & data->c) | ((~data->b) & data->d);
			tmp2 = i;
		}
		else if (i < 32)
		{
			tmp1 = (data->d & data->b) | ((~data->d) & data->c);
			tmp2 = (5 * i + 1) % 16;
		}
		else if (i < 48)
		{
			tmp1 = data->b ^ data->c ^ data->d;
			tmp2 = (3 * i + 5) % 16;
		}
		else
		{
			tmp1 = data->c ^ (data->b | (~data->d));
			tmp2 = (7 * i) % 16;
		}
		swap_and_rotate(data, i, tmp1, tmp2);
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
	t_md5	*d;
	int 	i;

	d = md5_init((unsigned char *)input_msg);

	while (d->offset < d->new_len)
	{
		d->tmp = (unsigned int *)(d->msg + d->offset);

		d->a = d->h[0];
		d->b = d->h[1];
		d->c = d->h[2];
		d->d = d->h[3];
		main_algorithm_loop(d, -1, 0, 0);
		d->h[0] += d->a;
		d->h[1] += d->b;
		d->h[2] += d->c;
		d->h[3] += d->d;

		d->offset += (512 / 8);
	}
	free(d->msg);
	i = -1;
	while (++i < 4)
		print_md5(d->h[i]);
}