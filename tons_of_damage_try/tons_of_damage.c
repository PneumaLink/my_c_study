#include <stdio.h>
#include <stdlib.h>

double	floating_point(double d){
	long	num;

	num = d * 100000000000;
	d = (double)num / 100000000000;
	return (d);
}

int	main(){
	int	total_try_input;
	int	total_try;
	int	try_input;
	int	try;
	double	input[4];
	double	ap;
	double	ad;
	double	*answer;

	scanf("%d", &total_try_input);	
	answer = (double*)calloc(total_try_input, sizeof(double));
	for (total_try = 0 ; total_try < total_try_input ; total_try++){
		scanf("%d %lf %lf %lf %lf", &try_input, &input[0], &input[1], &input[2], &input[3]);
		printf("\n");
		ad = 0;
		ap = 0;
		for (try = 0 ; try < try_input ; try++){
			ad = (ad * 2 * input[0] + (ad + 1) * input[1]) / (input[0] + input[1]);
			ap = (ap * 2 * input[2] + (ap + 1) * input[3]) / (input[2] + input[3]);
			answer[total_try] += ad * ap;
			printf("%d : %lf -> %lf\n", total_try, ad * ap, answer[total_try]);
		}
	}
	for (total_try = 0 ; total_try < total_try_input ; total_try++)
		printf("%lf\n", answer[total_try]);
	free(answer);
	return (0);
}
