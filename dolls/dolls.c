#include <stdio.h>
#include <math.h>

int	arr[500];

int	main(void){
	int	n_input1;
	int	k_input2;
	int	i;
	int	l;
	int	sum;
	double	average;
	double	dispersion;
	double	std_deviation;

	scanf("%d %d", &n_input1, &k_input2);
	sum = 0;
	for (i = 0 ; i < n_input1 ; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	average = (double)sum / (double)n_input1;
	std_deviation = 10;
	for (i = k_input2 - 1 ; i < n_input1 ; i++){
		dispersion = 0;
		for (l = i - k_input2 + 1; l <= i ; l++){
			dispersion += (double)(arr[l] - average) * (double)(arr[l] - average);
		}
		dispersion /= k_input2;
		if (std_deviation > sqrt(dispersion))
			std_deviation = sqrt(dispersion);
	}
	printf("%.11f", std_deviation);
	return (0);
}
