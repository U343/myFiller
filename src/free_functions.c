/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:16:35 by wanton            #+#    #+#             */
/*   Updated: 2020/08/01 13:31:48 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**Free two-dimensional array
 *
 * I don't know why i created this function
*/

void	free_buff(char **buff)
{
	int i;

	i = 0;
	while (buff[i])
		free(buff[i++]);
	free(buff);
}

void	free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->m)
		free(map->map[i++]);
	free(map->map);
	free(map);
}

void	free_token(t_token *token)
{
	int		i;

	i = 0;
	while (i < token->m)
		free(token->token[i++]);
	free(token->token);
	free(token);
}
