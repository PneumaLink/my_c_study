#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	scan_arr(int *arr, int value, int arr_size){
	int	scan_size;
	int	idx;
	int	i;
	int	sum;

	scan_size = 0;
	while(++scan_size <= arr_size){
		idx = -1;
		while(++idx < arr_size - scan_size + 1){
			i = idx;
			sum = 0;
			while(i < scan_size + idx){
				sum += arr[i++];
			}
			if (value <= sum)
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

int	partial_sum(char *user_input1, char *user_input2){
	int	sequence_size;
	int	reference_value;
	int	*sequence;
	int	answer;

	sequence_size = ft_atoi(user_input1);
	user_input1 = jump_to_next(user_input1);
	reference_value = ft_atoi(user_input1);
	sequence = str_to_int_arr(user_input2, sequence_size);
	if (!sequence)
		return (0);
	answer = scan_arr(sequence, reference_value, sequence_size);
	free(sequence);
	return (answer);
}

int	main(int argc, char *argv[]){
	int	answer;
	int	time1;
	int	time2;

	time1 = clock();
	if (argc != 3)
		printf("Please enter correct input!!\n");
	else{
		answer = partial_sum(argv[1], argv[2]);
		printf("%d\n", answer);
	}
	time2 = clock();
	printf("time : %d\n", time2 - time1);
	return (0);
}
