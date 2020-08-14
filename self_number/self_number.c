#include <stdio.h>

int	ft_sum(int num){
	int	sum;

	sum = 0;
	while(num){
		sum += num % 10;
		num /= 10;
	}
	return (sum);
}

int	main(){
	int	num[10001];
	int	i;
	int	idx;
	int	sum;

	for (idx = 1 ; idx < 10001 ; idx++)
		num[idx] = idx;
	for (idx = 1 ; idx < 10001 ; idx++){
		if (num[idx] == 0)
			continue ;
		printf("%d\n", num[idx]);
		for (i = idx ; i < 10001 ; i = sum){
			sum = 0;
			sum += i;
			sum += ft_sum(i);
			if (sum >= 10001)
				break;
			num[sum] = 0;
		}
	}
}
