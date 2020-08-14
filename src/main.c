/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:28:41 by wanton            #+#    #+#             */
/*   Updated: 2020/08/14 15:15:45 by wanton           ###   ########.fr       */
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

	if (get_next_line(DESCRIPTOR, &line) == -1)
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
	char		*line;
	int 		coords[2];
	FILE		*fd;

	fd = open_file();
	
	fp = open_file();
	if (!(filler = init_struct()))
		return (1);
	if (read_start(filler) == -1)
		return (1);
	line = ft_strnew(1000);
	while (get_next_line(DESCRIPTOR, &line) > -1)
	{
		if (ft_strncmp("Plateau ", line, 8) == 0)
		{
			read_map(filler->map, 4, line);
			init_hot_map(filler);
			create_hot_map(filler);
			write_trace_hot_map(filler, fd);
			write_trace(fd, "\n\n");
			ft_strdel(&line);
		}
		else if (ft_strncmp("Piece ", line, 6) == 0)
		{
			read_map(filler->token, 0, line);
			cut_dot(filler->token);
			find_place(filler, coords);
			ft_putnbr(coords[0]);
			ft_putchar(' ');
			ft_putnbr(coords[1]);
			ft_putchar('\n');
			free_int_buff(filler->hot_map, filler->map);
			free_buff(filler->map);
			free_buff(filler->token);
			ft_strdel(&line);
		}
		if (coords[0] == 0 && coords[1] == 0)
			break;
	}
	close_file(fd);
	ft_strdel(&line);
	free_filler(filler);
	close_file(fp);
	return (0);
}

