/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:05:46 by wanton            #+#    #+#             */
/*   Updated: 2020/07/29 15:53:48 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**This function read map.
 *
** - first gnl() read and dell string with numbers
** - str + 4 - it is necessary to skip numbers at the beginning of str
 *
**					Returned: 0 if successful | -1 if error with malloc
*/

int		read_map(t_map *map, FILE *fp) // fp для трейсов потом надо УДАЛИТЬ
{
	int 	i;
	char	*str;

	str = ft_strdup("Map:"); // trace. DELETE later
	write_trace(fp, str);
	free(str);
	
	i = 0;
	if (!(map->map = (char **)malloc(sizeof(char *) * map->m)))
		return (-1);
	get_next_line(0, &str);
	free(str);
	while (i < map->m)
	{
		if (get_next_line(0, &str) == -1)
			return (-1);
		if (!(map->map[i++] = ft_strdup(str + 4)))
			return (-1);
		free(str);
	}
	// trace. DELETE later
	i = 0;
	while (i < map->m)
		write_trace(fp, map->map[i++]);
	return (0);
}

/*
**Read size of token and set variables m and n for structs t_token
** m - rows
** n - columns
**					Returned: 0 if successful | -1 if error with malloc
*/

static void	read_token_size(t_token *token, FILE *fp)
{
	char	*line;
	char	**buff;
	char	*size1;
	char	*size2;

	get_next_line(0, &line);
	buff = ft_strsplit(line, ' ');
	size1 = ft_strdup(buff[1]);
	size2 = ft_strdup(buff[2]);
	token->m = ft_atoi(size1);
	token->n = ft_atoi(size2);
	
	// traces
	free_buff(buff);
	write_trace(fp, line);
	free(line);
	write_trace(fp, size1);
	free(size1);
	write_trace(fp, size2);
	free(size2);
}

/*
**This function read token.
**					Returned: 0 if successful | -1 if error with malloc
*/

int 	read_token(t_token *token, FILE *fp) //fp для трейсов потом надо УДАЛИТЬ
{
	char	*str;
	int 	i;

	str = ft_strdup("Size token:"); // trace. DELETE later
	write_trace(fp, str);
	free(str);
	
	read_token_size(token, fp);
	
	str = ft_strdup("Map:"); // trace. DELETE later
	write_trace(fp, str);
	free(str);
	
	i = 0;
	if (!(token->token = (char **)malloc(sizeof(char *) * token->m)))
		return (-1);
	while (i < token->m)
	{
		if (get_next_line(0, &str) == -1)
			return (-1);
		if (!(token->token[i] = ft_strdup(str)))
			return (-1);
		i++;
		free(str);
	}
	// trace. DELETE later
	i = 0;
	while (i < token->m)
		write_trace(fp, token->token[i++]);
	return (0);
}