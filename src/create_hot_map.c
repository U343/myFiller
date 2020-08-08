/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hot_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:55:46 by wanton            #+#    #+#             */
/*   Updated: 2020/08/08 15:04:57 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Check coords on valid. If coord placed into map and she is empty then coord
** is valid
 *
**        n, x, j
** -----------------
**                 |
**                 |
**                 |  m, y, i
**                 |
**                 |
*/

static int	is_valid_coords(t_filler *filler, int i, int j, int *flag)
{
	int 	m;
	int 	n;

	m = filler->map->y;
	n = filler->map->x;
	if ((i >= m || i < 0) || (j >= n || j < 0))
		return (0);
	else if (i == 0 && j == 0)
		return (0);
	else if (filler->hot_map[i][j] != EMPTY_CELL_NUMBER)
		return (0);
	*flag = 1;
	return (1);
}

/*
** Check and fill cells around cell with coords i, j
 *
** i - 1  |  i - 1  |  i - 1
** j - 1  |         |  j + 1
** -------------------------
**        |    i    |
** j - 1  |    j    |  j + 1
** -------------------------
** i + 1  |         |  i + 1
** j - 1  |  i + 1  |  j + 1
*/

static int	put_numbers(t_filler *filler, int num, int i, int j)
{
	int		flag;

	flag = 0;
	if (is_valid_coords(filler, i + 1, j, &flag) == 1)
		filler->hot_map[i + 1][j] = num;
	if (is_valid_coords(filler, i - 1, j, &flag) == 1)
		filler->hot_map[i - 1][j] = num;
	if (is_valid_coords(filler, i, j + 1, &flag) == 1)
		filler->hot_map[i][j + 1] = num;
	if (is_valid_coords(filler, i, j - 1, &flag) == 1)
		filler->hot_map[i][j - 1] = num;
	if (is_valid_coords(filler, i + 1, j + 1, &flag) == 1)
		filler->hot_map[i + 1][j + 1] = num;
	if (is_valid_coords(filler, i + 1, j - 1, &flag) == 1)
		filler->hot_map[i + 1][j - 1] = num;
	if (is_valid_coords(filler, i - 1, j + 1, &flag) == 1)
		filler->hot_map[i - 1][j + 1] = num;
	if (is_valid_coords(filler, i - 1, j - 1, &flag) == 1)
		filler->hot_map[i - 1][j - 1] = num;
	return (flag);
}

static void	filler_empty_cells(t_filler *filler)
{
	int		i;
	int 	j;
	int		tmp;

	i = -1;
	tmp = filler->map->x * filler->map->y;
	while (++i < filler->map->y)
	{
		j = -1;
		while (++j < filler->map->x)
		{
			if (filler->hot_map[i][j] == EMPTY_CELL_NUMBER)
				filler->hot_map[i][j] = tmp;
		}
	}
}

void		create_hot_map(t_filler *filler)
{
	int		flag;
	int		num;
	int 	i;
	int 	j;

	flag = 1;
	num = 1;
	while (flag == 1)
	{
		flag = 0;
		i = -1;
		while (++i < filler->map->y)
		{
			j = -1;
			while (++j < filler->map->x)
			{
				if (filler->hot_map[i][j] == num - 1)
					flag = (put_numbers(filler, num, i, j) == 0 ? flag : 1);
			}
		}
		num++;
	}
	filler_empty_cells(filler);
}