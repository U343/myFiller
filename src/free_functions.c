/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:16:35 by wanton            #+#    #+#             */
/*   Updated: 2020/07/29 15:32:52 by wanton           ###   ########.fr       */
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

void	free_map(t_map **map)
{
	free_buff((*map)->map);
	free(*map);
}

void	free_token(t_token **token)
{
	free_buff((*token)->token);
	free(*token);
}
