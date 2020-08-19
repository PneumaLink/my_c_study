#include <stdio.h>
#include <math.h>

int	arr[500];

double	floating_point(double f){
	long	i;
	i = f * 100000000000;
	f = (double)i / (double)100000000000;
	return (f);
}

int	main(void){
	int	n_input1;
	int	k_input2;
	long	sum;
	int	idx;
	int	cp_idx;
	double	n;
	double	average;
	double	std_deviation;
	double	variance;

	scanf("%d %d", &n_input1, &k_input2);
	for (idx = 0 ; idx < n_input1 ; idx++)
		scanf("%d", &arr[idx]);
	std_deviation = (double)pow(1000000 * 500, 2);
	for (idx = 0 ; idx < n_input1 - k_input2 + 1 ; idx++){
		sum = 0;
		for (cp_idx = idx ; cp_idx < idx + k_input2 ; cp_idx++)
			sum += arr[cp_idx];
		variance = 0;
		average = (double)sum / (double)k_input2;
		for (cp_idx = idx ; cp_idx < idx + k_input2 ; cp_idx++){
			n = arr[cp_idx] - average;
			variance += n * n;
		}
		variance = floating_point(sqrt(variance / (double)k_input2));
		if (std_deviation > variance)
			std_deviation = variance;
		if (idx + 1 >= n_input1 - k_input2 + 1){
			if (k_input2 < n_input1){
				k_input2++;
				idx = 0;
			}
		}
	}
	printf("%.6lf", std_deviation);
	return (0);
}
