#include <stdio.h>

void	ft_swap(int *arr, int left, int right){
	int	pivat;

	pivat = arr[left];
	arr[left] = arr[right];
	arr[right] = pivat;
}

void	ft_quick_sort(int *arr, int start, int end){
	int	left;
	int 	right;
	int	pin;

	pin = start;
	left = start + 1;
	right = end;
	while (1){
		for ( ; left <= end ; left++){
			if (arr[left] > arr[pin])
				break;
		}
		for ( ; right >= start ; right--){
			if (arr[right] < arr[pin])
				break;
		}
		if (left > right)
			break;
		ft_swap(arr, left, right);
	}
	if (start < end){
		ft_swap(arr, pin, right);
		ft_quick_sort(arr, start, right - 1);
		ft_quick_sort(arr, right + 1, end);
	}
}

int	main(){
	int	input[9];
	int	sum;
	int	idx;
	int	dwarf1;
	int	dwarf2;

	sum = 0;
	for (idx = 0; idx < 9 ; idx++){
		scanf("%d", &input[idx]);
		sum += input[idx];
	}
	sum -= 100;
	for (dwarf1 = 0 ; dwarf1 < 8 ; dwarf1++){
		for (dwarf2 = dwarf1 + 1 ; dwarf2 < 9 ; dwarf2++){
			if (input[dwarf1] + input[dwarf2] == sum)
				break;
		}
		if (input[dwarf1] + input[dwarf2] == sum)
			break;
	}
	printf("\n");
	ft_quick_sort(input, 0, 8);
	for (idx = 0 ; idx < 9 ; idx++){
		if (idx == dwarf1 || idx == dwarf2)
			continue ;
		printf("%d\n", input[idx]);
	}
	return (0);
}
