#include<stdio.h>

int	main(void){
	int	in1;
	int	in2;
	int	in3;

	while (1){
		scanf("%d %d %d", &in1, &in2, &in3);
		if (in2 - in1 > in3 - in2)
			printf("%d", in2 - in1 - 1);
		else
			printf("%d", in3 - in2 - 1);
	}
	return (0);
}
