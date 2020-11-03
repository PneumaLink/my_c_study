#include <stdio.h>

int	main()
{
	int	i, j;
	for (i = 0x00477dc4, j = 0x01084210; i; i >>= 1, j >>= 1){
		printf("d : %d %d\n", i ,j);
		printf("%c%c", (i&1)*('*' - 32) + 32, (j&1)*10);
	}
	printf("\n");
	return 0;
}
