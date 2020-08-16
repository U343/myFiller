/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:56:41 by wanton            #+#    #+#             */
/*   Updated: 2020/08/16 16:57:22 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**This function init struct t_man
**struct use for a token and for the main map
 *
** start and end coords use only for token
 *
*/

static t_map		*init_map()
{
	t_map		*tmp;
	
	if (!(tmp = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	tmp->x = 0;
	tmp->y = 0;
	tmp->start_x = -1;
	tmp->start_y = -1;
	tmp->end_x = -1;
	tmp->end_y = -1;
	tmp->map = NULL;
	return (tmp);
}

/*
**This function init struct t_filler, main struct
**
** player - symbol which we will play, default value is 'O'. Later can be
** replace on 'X'
*/

t_filler		*init_struct()
{
	t_filler	*tmp;

	if (!(tmp = (t_filler *)malloc(sizeof(t_filler))))
		return (NULL);
	if (!(tmp->map = init_map()))
		return (NULL);
	if (!(tmp->token = init_map()))
		return (NULL);
	tmp->player = FIRST_PLAYER_SYMBOL;
	tmp->enemy = SECOND_PLAYER_SYMBOL;
	tmp->hot_map = NULL;
	return (tmp);
}

int			init_hot_map(t_filler *filler)
{
	int 	i;
	int 	j;

	i = -1;
	if (!(filler->hot_map = (int **)malloc(sizeof(int *) * filler->map->y)))
		return (-1);
	while (++i < filler->map->y)
	{
		j = -1;
		if (!(filler->hot_map[i] = (int *)malloc(sizeof(int) * filler->map->x)))
			return (-1);
		while (++j < filler->map->x)
		{
			if (filler->map->map[i][j] == filler->player
				|| filler->map->map[i][j] == (filler->player + 32))
				filler->hot_map[i][j] = PLAYER_CELL_NUMBER;
			else if (filler->map->map[i][j] == filler->enemy
				|| filler->map->map[i][j] == (filler->enemy + 32))
				filler->hot_map[i][j] = ENEMY_CELL_NUMBER;
			else
				filler->hot_map[i][j] = EMPTY_CELL_NUMBER;
		}
	}
	return (0);
}