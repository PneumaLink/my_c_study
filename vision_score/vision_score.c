#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
https://code.sasa.hs.kr/problem.php?id=2309
*/

int	ft_calculating_score(char *map, int idx, int w, int s, int d)
{
	int	score;
	int	i;
	int	bush_f;

	score = 0;
	bush_f = 0;
	if (map[idx] == 'b' || map[idx] == 'H')
		bush_f = 1;
	score += s;
	if (map[idx] == 'e' || map[idx] == 'H')
		score += d;
	i = idx + 1;
	while (i <= idx + w)
	{
		if (map[i] != 'b' || map[i] != 'H')
			bush_f = 0;
		if ((map[i] == 'b' || map[i] == 'H') && bush_f)
			break;
		if (map[i] == 'e' || map[i] == 'H')
			score += d;
		score += s;
		i++;		
	}
	i = idx - 1;
	while (i >= idx - w)
	{
		if (map[i] != 'b' || map[i] != 'H')
			bush_f = 0;
		if ((map[i] == 'b' || map[i] == 'H') && bush_f)
			break;
		if (map[i] == 'e' || map[i] == 'H')
			score += d;
		score += s;
		i--;
	}
	return (score);
}

int	vision_score(char *map_value, char *enemy_ward, char *bush_location)
{
	int	answer;
	int	score;
	int	idx;
	char	*map;
	int	map_size;
	int	value;
	char	stack;
	int	ward_scan_size;
	int	number_of_enemy;
	int	number_of_bush;
	int	scan_score;
	int	defense_score;

	answer = 0;
	stack = 0;
	while (*map_value != '\0')
	{
		value = 0;
		while (*map_value != ' ' && *map_value != '\0')
		{
			value *= 10;
			value += *map_value - '0';
			map_value++;
		}
		stack++;
		if (stack == 1)
		{
			map_size = value;
			map = (char*)malloc(sizeof(char) * (map_size + 1));
			if (!map)
				return (-1);
			idx = 0;
			while(idx < map_size)
				map[idx++] = '_';
			map[idx] = '\0';
		}
		else if (stack == 2)
			ward_scan_size = value;
		else if (stack == 3)
			number_of_enemy = value;
		else if (stack == 4)
			number_of_bush = value;
		else if (stack == 5)
			scan_score = value;
		else if (stack == 6)
			defense_score = value;
		if (*map_value != '\0')
			map_value++;
	}
	while (*enemy_ward != '\0')
	{
		value = 0;
		while (*enemy_ward != ' ' && *enemy_ward != '\0')
		{
			value *= 10;
			value += *enemy_ward - '0';
			enemy_ward++;
		}
		map[value - 1] = 'e';	
		if (*enemy_ward != '\0')
			enemy_ward++;
	}
	while (*bush_location != '\0')
	{
		value = 0;
		while (*bush_location != ' ' && *bush_location != '\0')
		{
			value *= 10;
			value += *bush_location - '0';
			bush_location++;
		}
		if (map[value - 1] == 'e')
			map[value -1] = 'H';
		else
			map[value -1] = 'b';
		if (*bush_location != '\0')
			bush_location++;
	}
	idx = ward_scan_size;
	while (idx +  ward_scan_size <= map_size)
	{
		score = ft_calculating_score(map, idx, ward_scan_size, scan_score, defense_score);
		if (score > answer)
			answer = score;
		idx++;
	}
	free(map);
	return (answer);
}

int	main(int argc, char *argv[])
{
	time_t	t;
	time_t	t2;
	int	answer;

	t = clock();
	answer = 0;
	if (argc != 4)
	{
		printf("Please enter the correct input value!!!\n");
		return (0);
	}
	else
		answer = vision_score(argv[1], argv[2], argv[3]);
	printf("%d\n", answer);
	t2 = clock();
	printf("run_time : %ld\n", t2 - t);
	return (0);
}
