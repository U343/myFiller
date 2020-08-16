/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:05:46 by wanton            #+#    #+#             */
/*   Updated: 2020/08/16 14:06:47 by wanton           ###   ########.fr       */
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

static void	check_size(t_map *token)
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
				token->start_x = (j < token->start_x ? j : token->start_x);
				token->start_y = (i < token->start_y ? i : token->start_y);
				token->end_x = (j > token->end_x ? j : token->end_x);
				token->end_y = (i > token->end_y ? i : token->end_y);
			}
		}
	}
}

int		filler_new_token(t_map *token, char ***res)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = token->start_y - 1;
	y = 0;
	while (++i <= token->end_y)
	{
		j = token->start_x - 1;
		x = 0;
		if (!((*res)[y] = (char *)malloc(sizeof(char) * (token->end_x - j))))
			return (-1);
		while (++j <= token->end_x)
			(*res)[y][x++] = token->map[i][j];
		y++;
	}
	return (0);
}

int		cut_dot(t_map *token)
{
	int 	size;
	char	**res;

	token->start_x = token->x;
	token->start_y = token->y;
	token->end_x = 0;
	token->end_y = 0;
	check_size(token);
	size = token->end_y - token->start_y + 1;
	if (!(res = (char **)malloc(sizeof(char *) * size)))
		return (-1);
	if (filler_new_token(token, &res) == -1)
		return (-1);
	free_buff(token, MAP_IDENTIFIER);
	token->map = res;
	res = NULL;
	return (0);
}