#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

int	scan_arr(int *arr, int value, int arr_size){
	int	sum;
	int 	scan_size;
	int	i;
	
	scan_size = 0;
	while (++scan_size <= arr_size){
		sum = 0;
		i = 0;
		while (i<scan_size)
			sum += arr[i++];
		if (sum >= value)	
			return (scan_size);
		while (i < arr_size){
			sum -= arr[i - scan_size];
			sum += arr[i++];
			if (sum >= value)
				return (scan_size);
		}
	}
	return (0);
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
	while(*str && *str >= '0' && *str <= '9'){
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
	//int	time1;
	//int	time2;

	//time1 = clock();
	scanf("%d %d", &user_size, &user_value);
	user_input2 = (char*)malloc(sizeof(char) * (user_size * 2));
	getchar();
	fgets(user_input2, user_size * 2, stdin);
	answer = partial_sum(user_size, user_value, user_input2);
	printf("answer : %d\n", answer);
	//time2 = clock();
	//printf("time : %d\n", time2 - time1);
	return (0);
}
