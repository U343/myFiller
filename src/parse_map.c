/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:05:46 by wanton            #+#    #+#             */
/*   Updated: 2020/08/05 16:23:14 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**Read map size and set parameters n and m for t_map
 *
** m - rows
** n - columns
**					Returned: 0 if successful | -1 if error with malloc
*/

int		read_map_size(t_map *map)
{
	char	**buff;
	char	*line;

	if (get_next_line(0, &line) == -1)
		return (-1);
	if (!(buff = ft_strsplit(line, ' ')))
		return (-1);
	map->m = ft_atoi(buff[1]);
	map->n = ft_atoi(buff[2]);
	
	free_buff(buff);
	free(line);
	return (0);
}

/*
**This function read map and read token.
 *
** int offset - this variable use when we read main map
** if we read token offset = 0
** if we read main map offset = 4, because first line with numbers not use for
** algorithm and firstly 4 number on another string also not use
 *
** gnl() into (if (offset)) read and dell string with numbers
** str + offset - it is necessary to skip numbers at the beginning of str
 *
**					Returned: 0 if successful | -1 if error with malloc
*/

int		read_map(t_map *map, int offset)
{
	int 	i;
	char	*str;

	i = 0;
	read_map_size(map);
	if (!(map->map = (char **)malloc(sizeof(char *) * map->m)))
		return (-1);
	if (offset)
	{
		if (get_next_line(0, &str) == -1)
			return (-1);
		free(str);
	}
	while (i < map->m)
	{
		if (get_next_line(0, &str) == -1)
			return (-1);
		if (!(map->map[i++] = ft_strdup(str + offset)))
			return (-1);
		free(str);
	}
	return (0);
}
