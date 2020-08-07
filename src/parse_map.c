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
** String look like this - "Plateau 14 30:"
** 14 - rows; 30 - columns
 *
** ft_strchr - find first symbol number in string
** ft_strrchr - find last symbol number in string
**					Returned: 0 if successful | -1 if error with malloc
*/

int		read_map_size(t_map *map)
{
	char	*line;

	if (get_next_line(0, &line) == -1)
		return (-1);
	map->y = ft_atoi(ft_strchr(line, SPACE_SYMBOL));
	map->x = ft_atoi(ft_strrchr(line, SPACE_SYMBOL));
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
	if (!(map->map = (char **)malloc(sizeof(char *) * map->y)))
		return (-1);
	if (offset)
	{
		if (get_next_line(0, &str) == -1)
			return (-1);
		free(str);
	}
	while (i < map->y)
	{
		if (get_next_line(0, &str) == -1)
			return (-1);
		if (!(map->map[i++] = ft_strdup(str + offset)))
			return (-1);
		free(str);
	}
	return (0);
}
