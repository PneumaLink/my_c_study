#include <stdio.h>

int	main(void){
	int	input;
	int	answer;

	scanf("%d", &input);
	answer = 0;
	if (input < 3 || input == 4 || input == 7){
		printf("-1");
		return (0);
	}
	if ((input % 5) % 3 == 0){
		answer = input / 5;
		input = input % 5;
		answer += input / 3;
	}else if ((input % 5) % 3 == 1){
		answer = input / 5 - 1;
		input = input % 5 + 5;
		answer += input / 3;
	}else if ((input % 5) % 3 == 2){
		answer = input / 5 - 2;
		input = input % 5 + 10;
		answer += input / 3;
	}
	printf("%d", answer);
	return (0);
}
