#include <stdio.h>
#include <math.h>

int	arr[500];

double	floating_point(double f){
	long	i;
	i = f * 100000000000;
	f = (double)i / 100000000000;
	return (f);
}

int	main(void){
	int	n_input1;
	int	k_input2;
	int	i;
	int	l;
	int	sum;
	double	average;
	double	dispersion;
	double	std_deviation;
	double	n;

	scanf("%d %d", &n_input1, &k_input2);
	sum = 0;
	for (i = 0 ; i < n_input1 ; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	average = (double)sum / (double)n_input1;
	std_deviation = 1000000;
	for (i = k_input2 - 1 ; i < n_input1 ; i++){
		dispersion = 0;
		for (l = i - k_input2 + 1; l <= i ; l++){
			n = floating_point(arr[l] - average);
			dispersion += floating_point(pow(n * n, 0.5));
		}
		dispersion = floating_point(dispersion / k_input2);
		dispersion = floating_point(pow(dispersion, 0.5));
		if (std_deviation > dispersion)
			std_deviation = dispersion;
	}
	printf("%.11f", std_deviation);
	return (0);
}
