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