#include <stdio.h>

int	main(void){
	int	user_input;
	int	level;
	int	fibo[2] = {0 , 1};
	int	answer;

	scanf("%d", &user_input);
	if (user_input <= 0){
		printf("%d", 0);
		return (0);
	}
	if (user_input == 1){
		printf("%d", 1);
		return (0);
	}
	for (level = 2 ; level <= user_input ; level++){
		answer = (fibo[0] + fibo[1]) % 1000000007;
		fibo[0] = fibo[1];
		fibo[1] = answer;
	}
	printf("%d", answer);
	return (0);
}
