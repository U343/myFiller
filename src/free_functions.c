/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:16:35 by wanton            #+#    #+#             */
/*   Updated: 2020/08/15 14:55:01 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_token(t_map *map, int end)
{
	int i;
	
	i = 0;
	while (i < end)
		free(map->map[i++]);
	free(map->map);
}

/*
**Free two-dimensional array
 *
 * I don't know why i created this function
*/

void	free_buff(t_map *map)
{
	int i;

	i = 0;
	while (i < map->y)
		free(map->map[i++]);
	free(map->map);
}

void	free_int_buff(int **buff, t_map *map)
{
	int i;
	
	i = 0;
	while (i < map->y)
		free(buff[i++]);
	free(buff);
}

void	free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->y)
		free(map->map[i++]);
	free(map->map);
	free(map);
}

void	free_filler(t_filler *filler)
{
	free(filler->map);
	free(filler->token);
	free(filler);
}
