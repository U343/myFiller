/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:58:07 by wanton            #+#    #+#             */
/*   Updated: 2020/08/01 17:26:28 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**This function init struct t_man
**struct use for a token and for the main map
*/

static t_map		*init_map()
{
	t_map		*tmp;
	
	if (!(tmp = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	tmp->m = 0;
	tmp->n = 0;
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
	tmp->player = 'O';
	tmp->enemy = 'X';
	tmp->hot_map = NULL;
	return (tmp);
}

/*
**This function init hot_map: allocated memory and fill her
 *
** -1 - clear cell
** -2 - player cell
**  0 - enemy cell
 *
** 					Returned: 0 if successful | -1 if error with malloc
*/

int			init_hot_map(t_filler *map)
{
	int 	i;
	int 	j;

	i = -1;
	if (!(map->hot_map = (int **)malloc(sizeof(int *) * map->map->m)))
		return (-1);
	while (++i < map->map->m)
	{
		j = -1;
		if (!(map->hot_map[i] = (int *)malloc(sizeof(int) * map->map->n)))
			return (-1);
		while (++j < map->map->n)
		{
			if (map->map->map[i][j] == map->player
				|| map->map->map[i][j] == map->player + 32)
				map->hot_map[i][j] = -2;
			else if (map->map->map[i][j] == map->enemy
				|| map->map->map[i][j] == map->enemy + 32)
				map->hot_map[i][j] = 0;
			else
				map->hot_map[i][j] = -1;
		}
	}
	return (0);
}