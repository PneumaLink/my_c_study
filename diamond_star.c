#include <stdio.h>

int	main(void)
{
	int	n;
	int	len;
	int	flag;
	int	space;
	int	star;
	int	print_sign;
	int	sw;

	n = 9;
	flag = 0;
	print_sign = 0;
	for (len = 0 ; len >= 0 ; flag?len--:len++){
		for (space = 0 ; print_sign == 0 ; space++){
			for ( ; space == n/2 - len && print_sign == 0 ; print_sign++)
				;
			for ( sw = 0 ; print_sign == 0 && sw == 0 ; sw++){
				printf(" ");
			}
		}
		for (star = 0 ; print_sign == 1 ; star++){
			for ( ; star == len*2 + 1 && print_sign == 1 ; print_sign++)
				;
			for ( sw = 0 ; print_sign == 1 && sw == 0; sw++)
				printf("*");
		}
		for ( ; print_sign >= 2 ; print_sign = 0)
			printf("\n");
		for ( ; len == n/2 && flag == 0; flag = 1)
			;
	}
	return (0);
}
