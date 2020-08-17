/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:10:07 by wanton            #+#    #+#             */
/*   Updated: 2020/08/17 13:41:22 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	num(char symbol, int number, int *flag, int *sum)
{
	if (symbol == TOKEN_FILLED_SYMBOL)
	{
		if (number == PLAYER_CELL_NUMBER && *flag == 1)
			*flag = 0;
		else if (number != ENEMY_CELL_NUMBER && number != PLAYER_CELL_NUMBER)
			*sum += number;
		else
			return (-1);
	}
	return (0);
}

static int	check_place(t_filler *filler, int m, int n)
{
	int		i;
	int		j;
	int		flag;
	int		sum;
	int		save_n;

	i = -1;
	flag = 1;
	sum = 0;
	save_n = n;
	while (++i <= (filler->token->end_y - filler->token->start_y))
	{
		j = -1;
		n = save_n;
		while (++j <= (filler->token->end_x - filler->token->start_x))
		{
			if (num(filler->token->map[i][j], filler->hot_map[m][n++], &flag,
		&sum) == -1)
				return (0);
		}
		m++;
	}
	if (flag == 0)
		return (sum);
	return (0);
}

static void	init_coords(int coords[3], int x, int y)
{
	coords[0] = x;
	coords[1] = y;
}

int			find_place(t_filler *filler, int coords[3])
{
	int		i;
	int		j;
	int		min;
	int		flag;

	init_coords(coords, 0, 0);
	i = -1;
	flag = 1;
	while (++i < (filler->map->y - (filler->token->end_y -
	filler->token->start_y)))
	{
		j = -1;
		while (++j < (filler->map->x - (filler->token->end_x -
		filler->token->start_x)))
		{
			coords[2] = check_place(filler, i, j);
			if ((coords[2] > 0) && (flag == 1 || coords[2] < min))
			{
				flag = 0;
				min = coords[2];
				init_coords(coords, j, i);
			}
		}
	}
	return (flag);
}
