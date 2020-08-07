#include <stdio.h>

int arr[1002];

int	main(){
	int	n_input1;
	int	k_input2;
	int	i;
	int	d;
	int	stack;
	int	cp;

	stack = 0;
	cp = 0;
	scanf("%d %d", &n_input1, &k_input2);
	if (k_input2 == 0){
		printf("0");
		return (0);
	}
	for (i = 2 ; i <= n_input1; i++)
		arr[i] = i;
	for (i = 2 ; i <= n_input1 ; i++){
		for (d = 1 ; d*i <= n_input1 ; d++){
			if (arr[i * d] != 0){
				cp = arr[i * d];
				stack++;
			}
			if (stack == k_input2){
				printf("%d", cp);
				return (0);
			}
			arr[i * d] = 0;
		}
	}
	printf("%d", cp);
	return (0);
}
