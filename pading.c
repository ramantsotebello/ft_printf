


#include <stdio.h>
#include <string.h>

#define ZERO 3
#define LEFT 1
#define RIGHT 2
#define PLUS 1
#define MINUS 2

#define HEX 1
#define OCT 2


void	print_hash(char *str, int hex_oct)
{
	if (hex_oct == HEX)
		printf("0x");
	else
		printf("0");
	printf("%s", str);
}

int		value_test(char *val)
{
	if (val[0] == '-')
		return (1);
	return (0);
}

void	print_empty(int lr)
{
	int	i = -1;

	while (++i < lr)
		printf(".");
}

void	bullshitadd(char *val, int lr, int j)
{
	size_t len = strlen(val);

	len -= value_test(val);
	if (lr - len > 0)
	{
		if (j == LEFT)
			print_empty(lr - len - 1);
		if (val[0] != '-')
			printf("+");
		printf("%s", val);
		if (j == RIGHT)
			print_empty(lr - len - 1);
	}
}

void	padding(char *val, int  lr, int j, int zero)
{
	size_t len = strlen(val);

	if (lr - len > 0)
	{
		if (j == LEFT)
			printf("%s", val);
		while (lr > -1)
		{
			if (zero == ZERO)
				printf("0");
			else
			printf(" ");
			lr--;
		}
		if	(j == RIGHT)
			printf("%s", val);
	}
	else
		printf("%s", val);
}

int		main(void)
{
//	bullshitadd("42", 4, RIGHT);
//	padding("1415", 42, RIGHT, ZERO);
	print_hash("20", OCT);
	return (0);
}
