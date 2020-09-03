#include <stdio.h>
#include <stdlib.h>

char	str[251];

void	ft_gets(){
	char	c;
	int	idx;

	idx = 0;
	while (1){
		c = fgetc(stdin);
		if (c == '\n')
			break;
		str[idx++] = c;
	}
	str[idx] = '\0';
}

int	main(void){
	int	idx;
	int	line_num;
	char	*arr_char;
	int	*arr_int;

	line_num = 0;
	arr_char = (char*)malloc(sizeof(char));
	arr_int = (int*)malloc(sizeof(int));
 	while (1){
		ft_gets();
		if (str[0] == '#')
			break;
		line_num++;
		arr_char = (char*)realloc(arr_char, sizeof(char) * line_num);
		arr_int = (int*)realloc(arr_int, sizeof(int) * line_num);
		arr_char[line_num - 1] = str[0];
		arr_int[line_num -1] = 0;
		for (idx = 1 ; str[idx] != '\0' ; idx++){
			if (arr_char[line_num - 1] == str[idx] || arr_char[line_num - 1] == str[idx] + ('a' - 'A')){
				arr_int[line_num - 1]++;
			}
		}
	}
	for (idx = 0 ; idx < line_num ; idx++)
		printf("%c %d\n", arr_char[idx], arr_int[idx]);
	free(arr_char);
	free(arr_int);
	return (0);
}
