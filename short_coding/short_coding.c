#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	모든 시작은 가장 첫 번째 조건.
	첫번째 조건에 == 이 나온다면.
	A == B 라는 것이 나왔을 때, 남은 문장안의 모든 B를 A로 바꾼다.
	다음문장에서도 이를 따른다.
	
	만약 A == B 와 B == A가 동시에 나온다면. 후자를 제거한다.
	동시에 &도 하나 제거해서 숫자를 맞춰준다.
	-> 앞의 조건에서 B == A의 형태가 A == A로 변화한다. 따라서 이 경우에 제거하자.

	출력시에는 문장 조건 문장 && 문장 조건 문장 && 순서로 출력을 진행하며,
	!과 = 뒤에 = 를 붙여주고, &는 두번 출력하게 하여 형태를 맞춰준다.

	문자열 제거 함수
	문자열 복사 함수 : strcpy
*/

char	str[1000001];
char	simbol[1000001];
int	strlens[2];

char	**ft_split(char *str_input){
	char	**strs;
	int	i;
	int	idx;
	int	s_idx;

	s_idx = 0;
	strs = (char**)calloc(strlens[1] + 1, sizeof(char*));
	for (i = 0 ; i < strlens[1] ; i++){
		strs[i] = (char*)calloc(strlens[0],sizeof(char));
		for (idx = 0; *str_input && *str_input != '!' && *str_input != '=' && *str_input != '&' ; str_input++){
			strs[i][idx++] = *str_input;
		}
		str_input += 2;
	}
	return (strs);
}

void	ft_fgets(FILE *fl){
	char	c;

	c = '\0';
	for(strlens[0] = 0 ; c != '\n' ; strlens[0]++){
		c = fgetc(fl);
		if (c == '!' || c == '=' || c == '&'){
			if (c != '&')
				simbol[strlens[1]++] = c;
		}
		str[strlens[0]] = c;
	}
	str[strlens[0] - 1] = '\0';
	strlens[1]++;
}

void	ft_swap(char **strs, int i1, int i2){
	char	*cp;

	cp = strs[i1];
	strs[i1] = strs[i2];
	strs[i2] = cp;
}

void	ft_calculation(char **strs){
	int	i;
	int	idx;

	for(i = 0 ; i < strlens[1] - 1 ; i += 2){
		if (simbol[i] == '='){
			for (idx = i + 2 ; idx < strlens[1] - 1 ; idx += 2){
				if (!strcmp(strs[i + 1], strs[idx]))
					strcpy(strs[idx], strs[i]);
				if (!strcmp(strs[i + 1], strs[idx + 1])){
					strcpy(strs[idx + 1], strs[i]);
					ft_swap(strs, idx, idx + 1);
				}
				if (!strcmp(strs[idx], strs[idx + 1])){
					strcpy(strs[idx], "\0");
					strcpy(strs[idx + 1], "\0");
					simbol[idx] = '.';
					simbol[idx + 1] = '.';
				}
			}
		}
	}	
}

int	main(void){
	char	**strs;
	int	i;
	ft_fgets(stdin);
	strs = ft_split(str);
	ft_calculation(strs);

	for (i = 0 ; i < strlens[1] - 1 ; i += 2){
		if (simbol[i] != '.'){
			printf("%s%c%c%s", strs[i], simbol[i], simbol[i + 1], strs[i + 1]);
			if (i + 2 < strlens[i] - 1)
				printf("&&");
		}
	}

	for (i = 0 ; i < strlens[1] + 1 ; i++){
		free(strs[i]);
	}
	free(strs);
	return (0);
}
