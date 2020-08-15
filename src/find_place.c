/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:10:07 by wanton            #+#    #+#             */
/*   Updated: 2020/08/15 16:15:14 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int 	check_place(t_filler *filler, int m, int n)
{
	int 	i;
	int 	j;
	int 	flag;
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
			if (filler->token->map[i][j] == TOKEN_FILLED_SYMBOL)
			{
				if (filler->hot_map[m][n] == PLAYER_CELL_NUMBER && flag == 1)
					flag = 0;
				else if (filler->map->map[m][n] == MAP_EMPTY_SYMBOL)
					sum += filler->hot_map[m][n];
				else
					return (0);
			}
			n++;
		}
		m++;
	}
	if (flag == 0)
		return (sum);
	else
		return (0);
}

int		find_place(t_filler *filler, int coords[2])
{
	int 	i;
	int 	j;
	int 	min;
	int		sum;
	int 	flag;

	coords[0] = 0;
	coords[1] = 0;
	i = -1;
	flag = 1;
	while (++i < (filler->map->y - (filler->token->end_y -
	filler->token->start_y)))
	{
		j = -1;
		while (++j < (filler->map->x - (filler->token->end_x -
		filler->token->start_x)))
		{
			sum = check_place(filler, i, j);
			if ((sum > 0) && (flag == 1 || sum < min))
			{
				flag = 0;
				min = sum;
				coords[0] = j;
				coords[1] = i;
			}
		}
	}
	return (flag);
}