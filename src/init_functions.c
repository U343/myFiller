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
**This function init struct t_map
**
** player - symbol which we will play, default value is 'O'. Later can be
** replace on 'X'
*/

t_map		*init_map()
{
	t_map	*tmp;

	if (!(tmp = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	tmp->player = 'O';
	tmp->enemy = 'X';
	tmp->m = 0;
	tmp->n = 0;
	tmp->map = NULL;
	tmp->hot_map = NULL;
	return (tmp);
}

/*
**This function init struct t_token
*/

t_token		*init_token()
{
	t_token		*tmp;
	
	if (!(tmp = (t_token *)malloc(sizeof(t_token))))
		return (NULL);
	tmp->m = 0;
	tmp->n = 0;
	tmp->token = NULL;
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

int			init_hot_map(t_map *map)
{
	int 	i;
	int 	j;

	i = -1;
	if (!(map->hot_map = (int **)malloc(sizeof(int *) * map->m)))
		return (-1);
	while (++i < map->m)
	{
		j = -1;
		if (!(map->hot_map[i] = (int *)malloc(sizeof(int) * map->n)))
			return (-1);
		while (++j < map->n)
		{
			if (map->map[i][j] == map->player
				|| map->map[i][j] == map->player + 32)
				map->hot_map[i][j] = -2;
			else if (map->map[i][j] == map->enemy
				|| map->map[i][j] == map->enemy + 32)
				map->hot_map[i][j] = 0;
			else
				map->hot_map[i][j] = -1;
		}
	}
	return (0);
}