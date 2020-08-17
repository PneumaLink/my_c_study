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
	long long	sum;
	int	i;
	int	l;
	double	std_deviation;
	double	dispersion;

	scanf("%d %d", &n_input1, &k_input2);
	for (i = 0 ; i < n_input1 ; i++)
		scanf("%d", &arr[i]);
	std_deviation = 1000000;
	for (i = 0 ; i < n_input1 - k_input2 + 1 ; i++){
		sum = 0;
		for (l = i ; l < i + k_input2 ; l++)
			sum += arr[l];
		dispersion = 0;
		for (l = i ; l < i + k_input2 ; l++){
			dispersion +=floating_point((arr[l] - (double)sum / (double)k_input2) * (arr[l] - (double)sum / (double)k_input2));
			dispersion = floating_point(dispersion);
		}
		dispersion = sqrt(dispersion / (double)k_input2);
		if (std_deviation > dispersion)
			std_deviation = dispersion;
	}
	printf("%.11f", std_deviation);
	return (0);
}
