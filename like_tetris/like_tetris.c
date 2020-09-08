#include <stdio.h>
#include <stdlib.h>

int	score_list[5];
int	score_order[5] = {0, 1, 2, 3, 4};

void	ft_swap(int *arr, int num1, int num2){
	int	cp_num;

	cp_num = arr[num1];
	arr[num1] = arr[num2];
	arr[num2] = cp_num;
}

void	ft_sort_all(){
	int	big;
	int	big_idx;
	int	small_idx;

	big = 0;
	for (big_idx = 0 ; big_idx < 4 ; big_idx++){
		for (small_idx = 4 ; small_idx > big_idx ; small_idx--){
			if (score_list[small_idx - 1] < score_list[small_idx]){
				ft_swap(score_list, small_idx - 1, small_idx);
				ft_swap(score_order, small_idx - 1, small_idx);
			}
		}
	}
}

int	ft_find_good_layer(int idx, int *stack, char *c_arr, char *str){
	int	layer;
	int	cp_idx;
	int	try;
	int	cp_stack[3];

	cp_stack[0] = stack[0];
	cp_stack[1] = stack[1];
	cp_stack[2] = stack[2];
	for (try = 0, cp_idx = idx + 1 ; try < 3 && str[cp_idx] != '\0' ; try++, cp_idx++){
		for (layer = 0 ; layer < 3 ; layer++){
			if (c_arr[layer] == str[cp_idx])
				cp_stack[layer]++;
		}
	}
	for (try = 0 ; try < 5 ; try++){
		for (layer = 0 ; layer < 3 ; layer++){
			if (cp_stack[layer] >= score_order[try])
				break;
		}
	}
	return (layer);
}

/*
자리선정
	놓으려는 자리가 '\0'이면 그냥 둔다.

	마지막 layer의 문자가 현제의 문자와 같다면 현제 위치의 stack을 추가한다.

스택계산
	시기
		1. layer에 새로운 문자가 쌓일경우
		2. 문자열이 끝났을 때
*/

int	ft_tetris(char *str, int len){
	int	answer;
	int	layer;
	int	idx;
	int	try;
	int	stack_idx;
	int	stack[] = {0, 0, 0};
	char	c_arr[] = {'\0', '\0', '\0'};

	layer = 0;
	answer = 0;
	try = 0;
	for (idx = 0 ; idx < len && str[idx] ; idx++){
		while(1){
			if (c_arr[layer] == '\0'){
				try = 0;
				c_arr[layer] = str[idx];
				stack[layer]++;
				break;
			}else if (c_arr[layer] == str[idx]){
				try = 0;
				stack[layer]++;
				break;
			}else{
				printf("try : %d\n", try);
				if (try >= 2){
					try = 0;
					layer = ft_find_good_layer(idx, stack, c_arr, str);
					for(stack_idx = 0 ; stack_idx < 5 ; stack_idx++){
						if (score_order[stack_idx] == stack[layer])
							break;
					}
					answer += score_list[stack_idx];
					stack[layer] = 1;
					c_arr[layer] = str[idx];
					break ;
				}
				try++;
				layer++;
				if (layer >= 3){
					layer = 0;
				}
			}
			//만약 최대로 점수를 받을 수 있는 경우보다 많이 쌓이는 경우?
		}
	}
	for (layer = 0 ; layer < 3 ; layer++){
		for (stack_idx = 0 ; stack_idx < 5 ; stack_idx++){
			if (stack[layer] == score_order[stack_idx])
				break;
		}
		answer += score_list[stack_idx];
	}
	return (answer);
}

int	main(void){
	int	len_input;
	char	*str_input;
	int	answer;
	
	scanf("%d %d %d %d %d", &score_list[0], &score_list[1], &score_list[2], &score_list[3], &score_list[4]);
	scanf("%d", &len_input);
	str_input = (char*)malloc(len_input + 1);
	scanf("%s", str_input);
	ft_sort_all();
	answer = ft_tetris(str_input, len_input);
	printf("%d", answer);
	free(str_input);
	return (0);
}
