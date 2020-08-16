/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:16:35 by wanton            #+#    #+#             */
/*   Updated: 2020/08/16 14:08:19 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_buff(t_map *map, int identifier)
{
	int i;
	int end;

	i = 0;
	end = identifier == MAP_IDENTIFIER ? map->y : (map->end_y - map->start_y
			+ 1);
	while (i < end)
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

void	free_filler(t_filler *filler)
{
	free(filler->map);
	free(filler->token);
	free(filler);
}
