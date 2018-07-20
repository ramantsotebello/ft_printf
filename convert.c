
#include <stdio.h>
#include <stdlib.h>

#define CAP 1

size_t		number_len(size_t size, int base)
{
	size_t	i;

	i = 0;
	while (size > 0)
	{
		i++;
		size /= base;
	}
	return (i);
}

char		upper(int cap)
{
	if (cap == CAP)
		return ('A');
	return ('a');
}

char		*to_hex(size_t size, int cap)
{
	char	*hex;
	size_t	big;
	char	c;
	char	up;

	up = cap == CAP ? 'A' : 'a';
	big = number_len(size, 16);
	hex = (char*)malloc(sizeof(char) * big + 1);
	hex[big] = '\0';
	big--;
	while (size > 0)
	{
		c = size % 16;
		if (c < 10)
			hex[big] = c + '0';
		else
			hex[big] = c + up - 10;
		big--;
		size /= 16;
	}
	printf("it's hex is %s\n", hex);
	return (hex);
}

int		main(void)
{
	to_hex(121515235, 0);
	return (0);
}
