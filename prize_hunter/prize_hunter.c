#include <stdio.h>
#include <stdlib.h>

char	*ft_fgets(char *str, int len, FILE *fp){
	char	*p;
	int	c;

	for(p = str ; len > 0 ; len--){
		c = fgetc(fp);
		if (c == '\n')
			break;
		*p++ = c;
	}
	*p = '\0';
	return (str);
}

int	ft_strlen(char *str){
	int	num;

	num = 0;
	while(*str++)
		num++;
	return(num);
}

char	*ft_next_num(char *str){
	while (*str >= '0' && *str <= '9')
		str++;
	while ((*str < '0' || *str > '9') && *str)
		str++;
	return (str);
} 

int	ft_atoi(char *str){
	int	num;

	num = 0;
	while (*str >= '0' && *str <= '9'){
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num);
}

int	second_contest(int ranking){
	if (ranking == 0)
		return (0);
	if (ranking == 1)
		return (5120000);
	if (ranking <= 3)
		return (2560000);
	if (ranking <= 7)
		return (1280000);
	if (ranking <= 15)
		return (640000);
	if (ranking <= 31)
		return (320000);
	return (0);
}

int	first_contest(int ranking){
	if (ranking == 0)
		return (0);
	if (ranking == 1)
		return (5000000);
	if (ranking <= 3)
		return (3000000);
	if (ranking <= 6)
		return (2000000);
	if (ranking <= 10)
		return (500000);
	if (ranking <= 15)
		return (300000);
	if (ranking <= 21)
		return (100000);
	return (0);
}

int	main(void){
	int	number_of_attempts;
	int	i;
	int	total_prize;
	char	**contest_arr;
	char	*cp_str;

	scanf("%d", &number_of_attempts);
	i = -1;
	getchar();
	contest_arr = (char**)malloc(sizeof(char*) * number_of_attempts);
	while (++i < number_of_attempts){
		contest_arr[i] = (char*)malloc(sizeof(char) * 7);
		ft_fgets(contest_arr[i], 7, stdin);
	}
	i = -1;
	while (++i < number_of_attempts){
		total_prize = 0;
		total_prize += first_contest(ft_atoi(contest_arr[i]));
		cp_str = ft_next_num(contest_arr[i]);
		total_prize += second_contest(ft_atoi(cp_str));
		printf("%d\n", total_prize);
		free(contest_arr[i]);
	}
	free(contest_arr);
	return (0);
}
