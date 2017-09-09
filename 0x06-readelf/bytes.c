#include "readelf.h"


uint64_t get_byte_big_endian(uint64_t data, int size)
{
	switch (size)
	{
	case 2:
		return (be16toh(data));
	case 4:
		return (be32toh(data));
	case 8:
		return (be64toh(data));
	default:
		return (0);
	}
}

uint64_t get_byte_host(uint64_t data, int __attribute__((unused)) size)
{
	return (data);
}
