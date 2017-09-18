#include "readelf.h"

/**
 * get_byte_big_endian - convert bytes from MSB to LSB
 * @data: data to be converted
 * @size: the size of the data
 * Return: an unsigned long integer where the bytes are in the right order
 */
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

/**
 * get_byte_host - just return data without any modification
 * @data: data to be returned
 * @size: the size of the data
 * Return: an unsigned long integer in host order
 */
uint64_t get_byte_host(uint64_t data, int __attribute__((unused)) size)
{
	return (data);
}
