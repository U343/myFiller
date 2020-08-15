/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:05:46 by wanton            #+#    #+#             */
/*   Updated: 2020/08/15 14:21:00 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**Read map size and set parameters x and y for t_map
 *
**					Returned: 0 if successful | -1 if error with malloc
*/

int		read_map_size(t_map *map, char *line)
{
	map->y = ft_atoi(ft_strchr(line, SPACE_SYMBOL));
	map->x = ft_atoi(ft_strrchr(line, SPACE_SYMBOL));
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

int		read_map(t_map *map, int offset, char *line)
{
	int 	i;
	char	*str;

	i = -1;
	read_map_size(map, line);
	str = NULL;
	if (!(map->map = (char **)malloc(sizeof(char *) * map->y)))
		return (-1);
	if (offset == 4)
	{
		if (get_next_line(DESCRIPTOR, &str) == -1)
			return (-1);
		free(str);
	}
	while (++i < map->y)
	{
		if (get_next_line(DESCRIPTOR, &str) == -1)
			return (-1);
		if (!(map->map[i] = ft_strdup(str + offset)))
			return (-1);
		free(str);
	}
	return (0);
}

static void	check_size(t_map *token, int coords_start[2], int coords_end[2])
{
	int		i;
	int 	j;

	i = -1;
	while (++i < token->y)
	{
		j = -1;
		while (++j < token->x)
		{
			if (token->map[i][j] == TOKEN_FILLED_SYMBOL)
			{
				coords_start[0] = (j < coords_start[0] ? j : coords_start[0]);
				coords_start[1] = (i < coords_start[1] ? i : coords_start[1]);
				coords_end[0] = (j > coords_end[0] ? j : coords_end[0]);
				coords_end[1] = (i > coords_end[1] ? i : coords_end[1]);
			}
		}
	}
}

int		filler_new_token(t_map *token, int start[2], int end[2], char ***res)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = start[1] - 1;
	y = 0;
	while (++i <= end[1])
	{
		j = start[0] - 1;
		x = 0;
		if (!((*res)[y] = (char *)malloc(sizeof(char) * (end[0] - j))))
			return (-1);
		while (++j <= end[0])
			(*res)[y][x++] = token->map[i][j];
		y++;
	}
	return (0);
}

int		cut_dot(t_map *token, int coords_start[2], int coords_end[2])
{
	int 	size;
	char	**res;

	coords_start[0] = token->x;
	coords_start[1] = token->y;
	coords_end[0] = 0;
	coords_end[1] = 0;
	check_size(token, coords_start, coords_end);
	size = coords_end[1] - coords_start[1] + 1;
	if (!(res = (char **)malloc(sizeof(char *) * size)))
		return (-1);
	if (filler_new_token(token, coords_start, coords_end, &res) == -1)
		return (-1);
	free_buff(token);
	token->map = res;
	res = NULL;
	return (0);
}