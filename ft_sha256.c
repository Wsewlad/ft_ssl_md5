#include "ft_sha256.h"

void	reverse_bytes(t_sha256 *dt, unsigned char *hash)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		hash[i]      = (dt->h[0] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 4]  = (dt->h[1] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 8]  = (dt->h[2] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 12] = (dt->h[3] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 16] = (dt->h[4] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 20] = (dt->h[5] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 24] = (dt->h[6] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 28] = (dt->h[7] >> (24 - i * 8)) & 0x000000ff;
	}
}


void	append_length_bits2padding(t_sha256 *dt)
{
	dt->bitlen += dt->datalen * 8;
	dt->data[63] = dt->bitlen;
	dt->data[62] = dt->bitlen >> 8;
	dt->data[61] = dt->bitlen >> 16;
	dt->data[60] = dt->bitlen >> 24;
	dt->data[59] = dt->bitlen >> 32;
	dt->data[58] = dt->bitlen >> 40;
	dt->data[57] = dt->bitlen >> 48;
	dt->data[56] = dt->bitlen >> 56;
	modify_data(dt);
}

void get_hash(t_sha256 *dt, unsigned char *hash)
{
	unsigned int i;

	i = dt->datalen;

	if (dt->datalen < 56) {
		dt->data[i++] = 0x80;
		while (i < 56)
			dt->data[i++] = 0x00;
	}
	else {
		dt->data[i++] = 0x80;
		while (i < 64)
			dt->data[i++] = 0x00;
		modify_data(dt);
		ft_memset(dt->data, 0, 56);
	}
	append_length_bits2padding(dt);
	reverse_bytes(dt, hash);
}


void swap_and_append_data(t_sha256 *dt, unsigned int *buf)
{
	int 			i;
	unsigned int tmp1;
	unsigned int tmp2;
	unsigned int a[8];

	i = -1;
	while (++i < 8)
		a[i] = dt->h[i];
	i = -1;
	while (++i < 64)
	{
		tmp1 = a[7] + EP1(a[4]) + CH(a[4],a[5],a[6]) + g_sha256_k[i] + buf[i];
		tmp2 = EP0(a[0]) + MAJ(a[0],a[1],a[2]);
		a[7] = a[6];
		a[6] = a[5];
		a[5] = a[4];
		a[4] = a[3] + tmp1;
		a[3] = a[2];
		a[2] = a[1];
		a[1] = a[0];
		a[0] = tmp1 + tmp2;
	}
	i = -1;
	while (++i < 8)
		dt->h[i] += a[i];
}


void modify_data(t_sha256 *dt)
{
	int 			i;
	int 			j;
	unsigned int 	buf[64];

	i = -1;
	j = 0;
	while (++i < 16)
	{
		buf[i] = (dt->data[j] << 24) | (dt->data[j + 1] << 16) |
		(dt->data[j + 2] << 8) | (dt->data[j + 3]);
		j += 4;
	}
	i -= 1;
	while (++i < 64)
		buf[i] = SIG1(buf[i - 2]) + buf[i - 7] + SIG0(buf[i - 15]) + buf[i - 16];

	swap_and_append_data(dt, buf);
}


void 	save_and_update_msg(t_sha256 *dt, unsigned char *input_msg, size_t init_len)
{
	size_t	i;

	i = 0;
	while (i < init_len)
	{
		dt->data[dt->datalen] = input_msg[i];
		dt->datalen++;
		if (dt->datalen == 64)
		{
			modify_data(dt);
			dt->bitlen += 512;
			dt->datalen = 0;
		}
		i++;
	}
}


t_sha256	*sha256_init()
{
	t_sha256		*dt;

	dt = (t_sha256 *)malloc(sizeof(t_sha256));
	dt->h[0] = 0x6a09e667;
	dt->h[1] = 0xbb67ae85;
	dt->h[2] = 0x3c6ef372;
	dt->h[3] = 0xa54ff53a;
	dt->h[4] = 0x510e527f;
	dt->h[5] = 0x9b05688c;
	dt->h[6] = 0x1f83d9ab;
	dt->h[7] = 0x5be0cd19;
	dt->datalen = 0;
	dt->bitlen = 0;

	return dt;
}


void	ft_sha256(void *input_msg)
{
	t_sha256		*dt;
	unsigned char	hash[32];
	int 			i;

	dt = sha256_init();
	save_and_update_msg(dt, (unsigned char *)input_msg, ft_strlen((char *)input_msg));
	get_hash(dt, hash);

	i = -1;
	while (++i < 32)
		ft_printf("%2.2x", hash[i]);

}