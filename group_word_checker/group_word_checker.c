#include <stdio.h>
#include <stdlib.h>

char	str[101];

void	ft_fgets(char *str, FILE *fl){
	char	c;
	int	i;

	i = 0;
	while(1){
		c = fgetc(fl);
		if (c == '\n')
			break;
		str[i++] = c;
	}
	str[i] = '\0';
}

int	main(void){
	int	answer;
	int	n_input1;
	int	idx;
	int	str_idx;
	int	cp_si;
	int	flag;
	char	c;

	scanf("%d", &n_input1);
	answer = 0;
	fgetc(stdin);
	for (idx = 0 ; idx < n_input1 ; idx++){
		ft_fgets(str, stdin);
		flag = 1;
		c = str[0];
		for (str_idx = 1; str[str_idx] != '\0' ; str_idx++){
			if (c == str[str_idx])
				continue ;
			for (cp_si = str_idx ; str[cp_si] != '\0' ; cp_si++){
				if (c == str[cp_si]){
					flag = 0;
					break;
				}
			}
			if (c == str[cp_si])
				break;
			else
				c = str[str_idx];
		}
		if (flag)
			answer++;
	}
	printf("%d", answer);
	return (0);
}
