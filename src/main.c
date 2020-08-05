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

void	read_start(t_filler *map)
{
	char *line;

	get_next_line(0, &line);
	if ((ft_strstr(line, "p2")))
	{
		map->player = 'X';
		map->enemy = 'O';
	}
	free(line);
}

int		main(void) 
{
	char		*str;
	t_filler	*filler;

	if (!(filler = init_struct()))
		return (1);
	read_start(filler);
	
	read_map(filler->map, 4);
	
	
	read_map(filler->token, 0);
	free_filler(filler);
	ft_putstr("1 1\n");
	return (0);
}

