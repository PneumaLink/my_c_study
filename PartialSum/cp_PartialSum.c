#include <stdio.h>
#include <stdlib.h>

int	scan_arr(int *arr, int value, int arr_size){
	int	s;
	int	d;
	int	sum;
	int	size;

	d = 0;
	s = 0;
	sum = 0;
	size = arr_size;
	while (d < arr_size){
		while (sum < value && d < arr_size)
			sum += arr[d++];
		if (s == 0 && d >= arr_size && sum < value)
			return (0);
		while (sum >= value)
			sum -= arr[s++];
		if (size > d - s + 1)
			size = d - s + 1;
	}
	//	노답시 0 리턴 구현하기
	return (size);
}

char	*jump_to_next(char *str){
	while(*str != ' ' && *str)
		str++;
	while((*str < '0' || *str > '9') && *str)
		str++;
	return (str);
}

int	ft_atoi(char *str){
	int	num;

	num = 0;
	while(*str >= '0' && *str <= '9' && *str){
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num);
}

int	*str_to_int_arr(char *str, int	size){
	int	*arr;
	int	idx;

	arr = (int*)malloc(sizeof(int) * size);
	if (!arr)
		return (int*)0;
	while ((*str < '0' || *str > '9') && *str)
		str++;
	idx = 0;
	while(*str){
		arr[idx++] = ft_atoi(str);
		str = jump_to_next(str);
	}
	return (arr);
}

int	partial_sum(int user_size, int user_value, char *user_input2){
	int	answer;
	int	*sequence;

	sequence = str_to_int_arr(user_input2, user_size);
	if (!sequence)
		return (0);
	answer = scan_arr(sequence, user_value, user_size);
	free(sequence);
	return (answer);
}

int	main(void){
	int	answer;
	int	user_size;
	int	user_value;
	char	*user_input2;

	user_input2 = (char*)malloc(sizeof(char) * (user_size * 5 + user_size));
	getchar();
	fgets(user_input2, user_size * 5 + user_size, stdin);
	answer = partial_sum(user_size, user_value, user_input2);
	printf("answer : %d\n", answer);
	free(user_input2);
	return (0);
}
