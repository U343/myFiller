/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:28:41 by wanton            #+#    #+#             */
/*   Updated: 2020/08/05 16:32:32 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**Read first line and check symbol which we will play
**
** 'O' is default for init_functions()
*/

int		read_start(t_filler *map)
{
	char *line;

	if (get_next_line(0, &line) == -1)
		return (-1);
	if ((ft_strstr(line, "p2")))
	{
		map->player = SECOND_PLAYER_SYMBOL;
		map->enemy = FIRST_PLAYER_SYMBOL;
	}
	free(line);
	return (0);
}

int		main(void) 
{
	t_filler	*filler;
	FILE		*fp;

	if (!(filler = init_struct()))
		return (1);
	read_start(filler);
	
	read_map(filler->map, 4);
	init_hot_map(filler);
	fp = open_file();
	write_trace_hot_map(filler, fp);
	close_file(fp);
	
	read_map(filler->token, 0);
	free_filler(filler);
	ft_putstr("1 1\n");
	return (0);
}

