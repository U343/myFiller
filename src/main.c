/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:28:41 by wanton            #+#    #+#             */
/*   Updated: 2020/08/17 12:51:55 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	write_coords(int x_coord, int y_coord, int flag)
{
	if (flag != 1)
	{
		ft_putnbr(y_coord);
		ft_putchar(' ');
		ft_putnbr(x_coord);
		ft_putchar('\n');
	}
	else
		ft_putstr("0 0\n");
}

static int	call_map_functions(t_filler *filler, char *line, int offset)
{
	if (read_map(filler->map, offset, line) == -1)
		return (-1);
	if (init_hot_map(filler) == -1)
		return (-1);
	create_hot_map(filler);
	return (0);
}

static int	call_token_functions(t_filler *filler, char *line, int offset)
{
	int		coords[3];
	int		flag;
	int		x_coord;
	int		y_coord;

	if (read_map(filler->token, offset, line) == -1)
		return (-1);
	if (cut_dot(filler->token) == -1)
		return (-1);
	flag = find_place(filler, coords);
	x_coord = coords[0] - filler->token->start_x;
	y_coord = coords[1] - filler->token->start_y;
	write_coords(x_coord, y_coord, flag);
	free_int_buff(filler->hot_map, filler->map);
	free_buff(filler->map, MAP_IDENTIFIER);
	free_buff(filler->token, TOKEN_IDENTIFIER);
	return (flag);
}

int			main(void)
{
	t_filler	*filler;
	char		*line;
	int			flag;

	if (!(filler = init_struct()))
		return (1);
	if (read_start(filler) == -1)
		return (1);
	flag = 0;
	while (get_next_line(DESCRIPTOR, &line) > -1)
	{
		if (ft_strncmp("Plateau ", line, 8) == 0)
			flag = call_map_functions(filler, line, 4);
		else if (ft_strncmp("Piece ", line, 6) == 0)
			flag = call_token_functions(filler, line, 0);
		ft_strdel(&line);
		if (flag == 1)
			break ;
		else if (flag == -1)
			return (0);
	}
	if (line)
		ft_strdel(&line);
	free_filler(filler);
	return (0);
}
