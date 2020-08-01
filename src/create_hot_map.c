/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hot_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:55:46 by wanton            #+#    #+#             */
/*   Updated: 2020/08/01 17:58:33 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


int		check_nums(t_map *map, int m, int n, int a)
{
	if (m == map->m && n == map->n)
	{
		if (map->hot_map[m][n - 1] == a || map->hot_map[m -1][n] == a ||
				map->hot_map[m - 1][n - 1] == a)
			return (1);
	}
	else if (m == 0 && n == map->n)
	{
		if (map->hot_map[m][n - 1] == a || map->hot_map[m + 1][n] == a ||
			map->hot_map[m + 1][n - 1] == a)
			return (1);
	}
	else if (m == map->m && n == 0)
	{
		if (map->hot_map[m][n + 1] == a || map->hot_map[m - 1][n] == a ||
			map->hot_map[m - 1][n + 1] == a)
			return (1);
	}
	else if (m == 0 && n == 0)
	{
		if (map->hot_map[0][1] == a || map->hot_map[1][0] == a ||
			map->hot_map[1][1] == a)
			return (1);
	}
	else if (m == map->m)
	{
		if (map->hot_map[m][n + 1] == a || map->hot_map[m][n - 1] == a ||
			map->hot_map[m - 1][n + 1] == a || map->hot_map[m - 1][n -1] == a
			|| map->hot_map[m - 1][n] == a)
			return (1);
	}
	else if (m == 0)
	{
		if (map->hot_map[m][n + 1] == a || map->hot_map[m][n - 1] == a ||
			map->hot_map[m + 1][n + 1] == a || map->hot_map[m + 1][n -1] == a
			|| map->hot_map[m + 1][n] == a)
			return (1);
	}
	else if (n == map->n)
	{
		if (map->hot_map[m][n - 1] == a || map->hot_map[m - 1][n] == a ||
		map->hot_map[m + 1][n] == a || map->hot_map[m - 1][n - 1] == a ||
				map->hot_map[m + 1][n - 1] == a)
			return (1);
	}
	else if (n == 0)
	{
		if (map->hot_map[m][n + 1] == a || map->hot_map[m - 1][n] == a ||
			map->hot_map[m + 1][n] == a || map->hot_map[m - 1][n + 1] == a ||
			map->hot_map[m + 1][n + 1] == a)
			return (1);
	}
	return (0);
}

/*
**This functions create hot map
 *
**  -2 - our token
**  -1 - enemy token
**  other number - distance to enemy
*/

int		create_hot_map(t_map *map, FILE *fp)
{
	int		i;
	int 	j;
	int		number;
	char	flag;

	flag = 0;
	number = 1;
	init_hot_map(map);
	write_trace_hot_map(map, fp);
	while (flag == 0)
	{
		flag = 1;
		i = -1;
		while (++i < map->m)
		{
			j = -1;
			while (++j < map->n)
			{
				if (map->hot_map[i][j] == -1)
				{
					flag = 0;
					if (check_nums(map, i, j, number - 1) == 1)
						map->hot_map[i][j] = number;
				}
			}
			number++;
		}
	}
	write_trace_hot_map(map, fp);
	return (0);
}