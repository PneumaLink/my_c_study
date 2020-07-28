#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	put_nbr(int **snail, int n){
	int	y;
	int	x;
	int	flag;
	int	num;
	int	split;

	y = 0;
	x = 0;
	flag = 0;
	num = 1;
	split = 0;
	while(1){
		snail[y][x] = num;
		if (num++ == n * n)
			break ;
		switch (flag){
			case 0:
				if (x == n - 1 - split){	
					y++;
					flag = 1;
				}
				else
					x++;
				break ;
			case 1:
				if (y == n - 1 - split){	
					x--;
					flag = 2;
				}
				else
					y++;
				break ;
			case 2:
				if (x == split){
					y--;
					split++;
					flag = 3;
				}
				else
					x--;
				break ;
			case 3:
				if (y == split){
					x++;
					flag = 0;
				}
				else
					y--;
				break;
		}
	}
}

int	**make_snail_house(int	n){
	int	**snail_house;
	int	idx;
	int	i;

	idx = 0;
	if (!(snail_house = (int**)malloc(sizeof(int*) * n)))
		return (NULL);
	while (idx < n){
		snail_house[idx] = (int*)malloc(sizeof(int) * n);
		if (!snail_house[idx])
			return (NULL);
		i = 0;
		idx++;
	}
	snail_house[idx] = NULL;
	return (snail_house);
}

int	ft_atoi(char *num_char){
	int	num;

	num = 0;
	while (*num_char != '\0'){
		if (*num_char < '0' || *num_char > '9')
			return (-10);
		num *= 10;
		num += *num_char++ - '0';
	}
	return (num);
}

int	main(int argc, char *argv[]){
	int	n;
	int	**snail;
	int	idx;
	int	i;

	if (argc != 2){
		printf("The number of input must be only one!\n");
		return (0);
	}
	n = ft_atoi(argv[1]);
	if (n < 2){
		if (n < 0)		
			printf("Input value must be '0' ~ '9'\n");
		else
			printf("Input value must be more then 2\n");
		return (0);
	}
	if (!(snail = make_snail_house(n))){
		printf("malloc error!\n");
		return (0);
	}
	put_nbr(snail, n);
	idx = 0;
	while (idx < n){
		i = 0;
		while (i < n)
			printf(" %3d ", snail[idx][i++]);
		printf("\n");
		idx++;
	}
	idx = 0;
	while (idx < n)
		free(snail[idx++]);
	free(snail);
	return (0);
}
