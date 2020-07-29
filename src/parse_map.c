/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:05:46 by wanton            #+#    #+#             */
/*   Updated: 2020/07/29 15:00:36 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**This function read map.
 *
** - first gnl() read and dell string with numbers
** - str + 4 - it is necessary to skip numbers at the beginning of str
 *
**					Returned: 0 if successful | -1 if error with malloc
*/

int		read_map(t_map *map, FILE *fp) // fp для треймсов потом надо УДАЛИТЬ
{
	int 	i;
	char	*str;
	char	**board;
	
	str = ft_strdup("Map:"); // trace. DELETE later
	write_trace(fp, str);
	free(str);
	
	i = 0;
	if (!(board = (char **)malloc(sizeof(char *) * map->m + 1)))
		return (-1);
	get_next_line(0, &str);
	free(str);
	while (i < map->m)
	{
		if (get_next_line(0, &str) == -1)
			return (-1);
		board[i++] = ft_strdup(str + 4);
		free(str);
	}
	// trace. DELETE later
	i = 0;
	while (i < map->m)
		write_trace(fp, board[i++]);
	return (0);
}